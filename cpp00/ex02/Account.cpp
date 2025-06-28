#include "Account.hpp"
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	_nbAccounts += 1;
	_totalAmount += initial_deposit;

	_accountIndex = _nbAccounts - 1;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_displayTimestamp();
	std::cout
			<< "index:" << this->_accountIndex << ";"
			<< "amount:" << this->_amount << ";"
			<< "created"
			<< std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout
			<< "index:" << this->_accountIndex << ";"
			<< "amount:" << this->_amount << ";"
			<< "closed"
			<< std::endl;
}

// ============ Getters ============

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}
int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}
int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

// ===================================

void	Account::makeDeposit(int deposit)
{
	this->_amount += deposit;
	this->_nbDeposits++;

	_totalNbDeposits++;
	_totalAmount += deposit;

	_displayTimestamp();
	std::cout
			<< "index:" << this->_accountIndex << ";"
			<< "p_amount:" << this->_amount - deposit << ";"
			<< "deposit:" << deposit << ";"
			<< "amount:" << this->_amount << ";"
			<< "nb_deposits:" << this->_nbDeposits
			<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (this->_amount >= withdrawal)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;

		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;

		_displayTimestamp();
		std::cout
				<< "index:" << this->_accountIndex << ";"
				<< "p_amount:" << this->_amount + withdrawal << ";"
				<< "withdrawal:" << withdrawal << ";"
				<< "amount:" << this->_amount << ";"
				<< "nb_withdrawals:" << this->_nbWithdrawals
				<< std::endl;

		return (true);
	}
	else
	{
		_displayTimestamp();
		std::cout
				<< "index:" << this->_accountIndex << ";"
				<< "p_amount:" << this->_amount << ";"
				<< "withdrawal:refused"
				<< std::endl;
		return (false);
	}
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout
			<< "index:" << this->_accountIndex << ";"
			<< "amount:" << this->_amount << ";"
			<< "deposits:" << this->_nbDeposits << ";"
			<< "withdrawals:" << this->_nbWithdrawals
			<< std::endl;
}


void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout
			<< "accounts:" << getNbAccounts() << ";"
			<< "total:" << getTotalAmount() << ";"
			<< "deposits:" << getNbDeposits() << ";"
			<< "withdrawals:" << getNbWithdrawals()
			<< std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t current_time = std::time(NULL);
	std::tm* t = std::localtime(&current_time);

	std::cout << '['
			  << (t->tm_year + 1900)
			  << std::setfill('0')
			  << std::setw(2) << (t->tm_mon + 1)
			  << std::setw(2) << t->tm_mday
			  << '_'
			  << std::setw(2) << t->tm_hour
			  << std::setw(2) << t->tm_min
			  << std::setw(2) << t->tm_sec
			  << ']'
			  << ' ';
}
