#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <stdio.h>

#include <algorithm>
#include <stdexcept>
#include <vector>
#include <deque>

class PmergeMe
{
private:

	static const int	max_size;

	/* -------------------------------------------------------------- */
	/* VECTOR IMPLEMENTATION                                          */
	/* -------------------------------------------------------------- */

	void	_mergeInsertSort(std::vector<unsigned int>& elements);

	void	_insertLosers(std::vector<unsigned int>& mainChain, 
			const std::vector<unsigned int>& losers,
			const std::vector<std::pair<unsigned int, unsigned int> >& pairs);


	/* -------------------------------------------------------------- */
	/* DEQUE IMPLEMENTATION                                           */
	/* -------------------------------------------------------------- */

 	void	_mergeInsertSort(std::deque<unsigned int>& elements);

	void	_insertLosers(std::deque<unsigned int>& mainChain, 
			const std::deque<unsigned int>& losers,
			const std::deque<std::pair<unsigned int, unsigned int> >& pairs);

	/* -------------------------------------------------------------- */
	/* SHARED HELPERS                                                 */
	/* -------------------------------------------------------------- */ 

	size_t	_getJacobsthalNumber(size_t n);

	static bool comparePairs(const std::pair<unsigned int, unsigned int>& a, 
							const std::pair<unsigned int, unsigned int>& b);

public:
	PmergeMe();
	PmergeMe(PmergeMe& other);
	~PmergeMe();

	void	sort(std::vector<unsigned int>& elements);
	void	sort(std::deque<unsigned int>& elements);

	PmergeMe&	operator=(PmergeMe& other);
};

#endif