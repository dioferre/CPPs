
#include "PmergeMe.hpp"

// The subject asks for a max_size of 3k ints minimum.
// I'm hard capping it at this very specific numbe since
// it'ts the highest number in the same cost tier for binary search as 3000.
// I could simply cap it at 3000, but since they have the same comparison cost, it's fine.
// Anything that goes over this would go over 14 comparisons for a binary search so won't be permitted.
const int	PmergeMe::max_size = 5461;

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe& other) { *this = other; }

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(PmergeMe& other)
{
	if (this != &other)
	{ }
	return (*this);
}

// =============================================================================
//                             PUBLIC METHODS
// =============================================================================

void	PmergeMe::sort(std::vector<unsigned int>& elements)
{
	if (elements.size() <= 1) {
		throw std::invalid_argument("Vector size too small. Minimum size is: 2.");
	} else if (elements.size() > static_cast<std::size_t>(max_size)) {
		throw std::invalid_argument("Vector size too big. Maximum size is: 5461.");
	}

	_mergeInsertSort(elements);
}

void    PmergeMe::sort(std::deque<unsigned int>& elements)
{
    if (elements.size() <= 1) {
        throw std::invalid_argument("Deque size too small. Minimum size is: 2.");
    } else if (elements.size() > max_size) {
        throw std::invalid_argument("Deque size too big. Maximum size is: 5461.");
    }

    _mergeInsertSort(elements);
}

// returns the JacobsthalNumber at N'th place.
// basically, what amount will need N binary comparisons to sort.
size_t PmergeMe::_getJacobsthalNumber(size_t n)
{
	static const size_t jacobsthal_nums[] = {
		1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461
	};

	if (n > 13)
		return (0); // should never happen since it's controlled in the sort method.

	return (jacobsthal_nums[n]);
}

// =============================================================================
//                             VECTOR IMPLEMENTATION
// =============================================================================

std::vector<std::pair<unsigned int, unsigned int> >	PmergeMe::_sortPairs
	(std::vector<std::pair<unsigned int, unsigned int> >& pairs,
	std::vector<unsigned int>& winners)
{
	std::vector<std::pair<unsigned int, unsigned int> > reordered_pairs;
	
	for (size_t i = 0; i < winners.size(); ++i)
	{
		unsigned int w = winners[i];
	
		// Find the corresponding pair in our unsorted 'pairs' list
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (pairs[j].first == w)
			{
				reordered_pairs.push_back(pairs[j]);
				// Optimization: Remove found pair from 'pairs' to speed up future searches,
				// In a vector, erasing is slow, so just leave it be instead.
				break; 
			}
		}
	}
	
	return (reordered_pairs);
}

void	PmergeMe::_mergeInsertSort(std::vector<unsigned int>& elements)
{
	if (elements.size() <= 1)
		return ;

	std::vector<unsigned int> winners;
	std::vector<unsigned int> losers;

	std::vector<std::pair<unsigned int, unsigned int> > pairs;

	// slight performance boost, it reserves memory for the vectors so no resizing neeed
	size_t half_size = elements.size() / 2;
	winners.reserve(half_size);
	losers.reserve(half_size);
	pairs.reserve(half_size);

	for (size_t i = 0; i < elements.size() / 2; i++)
	{
		unsigned int	a = elements[2*i];
		unsigned int	b = elements[2*i + 1];

		if (a > b)
		{
			pairs.push_back(std::make_pair(a, b));
			winners.push_back(a);
			losers.push_back(b);
		}
		else
		{
			pairs.push_back(std::make_pair(b, a));
			winners.push_back(b);
			losers.push_back(a);
		}
	}

	//	In case there is a straggler left over, it's pushed onto the losers.
	if (elements.size() % 2 != 0)
	{
		losers.push_back(elements.back());
	}
	
	_mergeInsertSort(winners);
	// * the winners container is now sorted and will become our main chain from here.


	// * Since the winners are now ordered, we're going to order the original pairs based on that.
	// * Making a new container is significantally more efficient than reutilizing the old one.
	// * This is not cheating since the _sortPairs method only uses the '==' comparison, which doesn't count for the algorithm.
	std::vector<std::pair<unsigned int, unsigned int> > reordered_pairs =
		 _sortPairs(pairs, winners);

	_insertLosers(winners, losers, reordered_pairs);

	elements = winners;
}

void PmergeMe::_insertLosers (std::vector<unsigned int>& mainChain, 
							const std::vector<unsigned int>& losers,
							const std::vector<std::pair<unsigned int, unsigned int> >& pairs)
{
	// Usually, the straggler is the last element in 'losers' that isn't in 'pairs'.
	bool hasStraggler = (losers.size() > pairs.size());

	// Insert the first loser (b1)
	// We know b1 < a1, so it always goes at the very front.
	if (!pairs.empty())
	{
		mainChain.insert(mainChain.begin(), pairs[0].second);
	}

	// Insert the rest using Jacobsthal Sequence
	// Sequence indices to process: 3, 2, then 5, 4, then 11...
	// Note: We use 1-based indexing for Jacobsthal logic, but 0-based for vector access.

	size_t jacobsthalIdx = 2; // Start from the 3rd Jacobsthal number (value 3)
	size_t lastInsertedIndex = 0; // We just processed index 0 (b1)
	size_t pendingCount = pairs.size();

	while (lastInsertedIndex < pendingCount - 1)
	{
		size_t nextLimit = _getJacobsthalNumber(jacobsthalIdx);
		
		// Use the Jacobsthal number as the upper bound (exclusive 0-based index)
		// Cap it at the number of pending losers we actually have.
		size_t rightBound = nextLimit;
		if (rightBound > pendingCount)
			rightBound = pendingCount;

		// Iterate backwards from the limit down to the last inserted index
		// Example: If J=3, we process indices 2, then 1.
		for (size_t i = rightBound - 1; i > lastInsertedIndex; --i)
		{
			// O(1) Access: We know exactly which loser and winner we are dealing with
			unsigned int loserValue = pairs[i].second;
			unsigned int winnerValue = pairs[i].first;

			// Since the winner is guaranteed to be in the chain, lower_bound finds it with binary search.
			std::vector<unsigned int>::iterator winnerPos = 
				std::lower_bound(mainChain.begin(), mainChain.end(), winnerValue);
			
			// Binary search for the insertion point [begin, winnerPos)
			std::vector<unsigned int>::iterator insertPos = 
				std::upper_bound(mainChain.begin(), winnerPos, loserValue);
			
			// Insert
			mainChain.insert(insertPos, loserValue);
		}

		lastInsertedIndex = rightBound - 1; // -1 because index 0 is 1st element
		jacobsthalIdx++;
	}

	// Handle the Straggler
	// If there was an odd element out, it has no paired winner (conceptually winner is infinity).
	// We insert it into the entire list.
	if (hasStraggler)
	{
		unsigned int straggler = losers.back();
		std::vector<unsigned int>::iterator insertPos = 
			std::upper_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(insertPos, straggler);
	}
}
// =============================================================================
//                             DEQUE IMPLEMENTATION
// =============================================================================

std::deque<std::pair<unsigned int, unsigned int> > PmergeMe::_sortPairs(
	std::deque<std::pair<unsigned int, unsigned int> >& pairs,
	std::deque<unsigned int>& winners)
{
	std::deque<std::pair<unsigned int, unsigned int> > reordered_pairs;
	
	for (size_t i = 0; i < winners.size(); ++i)
	{
		unsigned int w = winners[i];
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (pairs[j].first == w)
			{
				reordered_pairs.push_back(pairs[j]);
				break; 
			}
		}
	}
	return (reordered_pairs);
}

void    PmergeMe::_mergeInsertSort(std::deque<unsigned int>& elements)
{
	if (elements.size() <= 1)
		return ;

	std::deque<unsigned int> winners;
	std::deque<unsigned int> losers;
	std::deque<std::pair<unsigned int, unsigned int> > pairs;

	for (size_t i = 0; i < elements.size() / 2; i++)
	{
		unsigned int a = elements[2*i];
		unsigned int b = elements[2*i + 1];

		if (a > b) {
			pairs.push_back(std::make_pair(a, b));
			winners.push_back(a);
			losers.push_back(b);
		} else {
			pairs.push_back(std::make_pair(b, a));
			winners.push_back(b);
			losers.push_back(a);
		}
	}

	if (elements.size() % 2 != 0) {
		losers.push_back(elements.back());
	}
	
	_mergeInsertSort(winners);

	std::deque<std::pair<unsigned int, unsigned int> > reordered_pairs = 
		_sortPairs(pairs, winners);

	_insertLosers(winners, losers, reordered_pairs);

	elements = winners;
}

void PmergeMe::_insertLosers (std::deque<unsigned int>& mainChain, 
							const std::deque<unsigned int>& losers,
							const std::deque<std::pair<unsigned int, unsigned int> >& pairs)
{
	bool hasStraggler = (losers.size() > pairs.size());

	if (!pairs.empty()) {
		mainChain.insert(mainChain.begin(), pairs[0].second);
	}

	size_t jacobsthalIdx = 2; 
	size_t lastInsertedIndex = 0; 
	size_t pendingCount = pairs.size();

	while (lastInsertedIndex < pendingCount - 1)
	{
		size_t nextLimit = _getJacobsthalNumber(jacobsthalIdx);
		size_t rightBound = nextLimit;
		if (rightBound > pendingCount)
			rightBound = pendingCount;

		for (size_t i = rightBound - 1; i > lastInsertedIndex; --i)
		{
			unsigned int loserValue = pairs[i].second;
			unsigned int winnerValue = pairs[i].first;

			std::deque<unsigned int>::iterator winnerPos = 
				std::lower_bound(mainChain.begin(), mainChain.end(), winnerValue);
			
			std::deque<unsigned int>::iterator insertPos = 
				std::upper_bound(mainChain.begin(), winnerPos, loserValue);
			
			mainChain.insert(insertPos, loserValue);
		}
		lastInsertedIndex = rightBound - 1; 
		jacobsthalIdx++;
	}

	if (hasStraggler) {
		unsigned int straggler = losers.back();
		std::deque<unsigned int>::iterator insertPos = 
			std::upper_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(insertPos, straggler);
	}
}