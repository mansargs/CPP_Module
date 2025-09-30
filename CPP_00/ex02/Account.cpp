#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}
int	Account::getTotalAmount(void)
{
	return _totalAmount;
}
int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

 void	Account::_displayTimestamp(void)
{
	std::time_t now_long = std::time(0);

	std::tm *now = std::localtime(&now_long);
	std::cout << '['
		  << (now->tm_year + 1900)
		  << std::setw(2) << std::setfill('0') << (now->tm_mon + 1)
		  << std::setw(2) << std::setfill('0') << now->tm_mday << '_'
		  << std::setw(2) << std::setfill('0') << now->tm_hour
		  << std::setw(2) << std::setfill('0') << now->tm_min
		  << std::setw(2) << std::setfill('0') << now->tm_sec
		  << ']';
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts
			  << ";total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account(void) : _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
	++Account::_nbAccounts;
	_accountIndex = Account::_nbAccounts - 1;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

Account::Account(int initial_deposit) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	++Account::_nbAccounts;
	_accountIndex = Account::_nbAccounts - 1;
	Account::_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}

void	Account::makeDeposit(int deposit)
{
	_nbDeposits++;
	Account::_totalNbDeposits++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount;
	_amount += deposit;
	Account::_totalAmount += deposit;
    std::cout << ";deposit:" << deposit << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (_amount < withdrawal)
	{
		std::cout << "refused\n";
		return false;
	}
	else
	{
		_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
        std::cout << withdrawal << ";amount:" << _amount
				  << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	}
	return true;
}

int	Account::checkAmount(void) const
{
	return _amount;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals << std::endl;
}


