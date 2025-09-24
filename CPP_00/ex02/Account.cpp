#include "Account.hpp"
#include <iostream>
#include <ctime>

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
	std::cout << '[' << now->tm_year + 1900 << now->tm_mon << now->tm_mday << '_'
			<< now->tm_hour << now->tm_min << now->tm_sec << ']';
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
	_amount += deposit;
	Account::_totalAmount += deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:"
			  << deposit << ";_amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
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
		std::cout << withdrawal << ";_amount:" << _amount
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
			  << ";amout:" << _amount
			  << ";deposit:" << _nbDeposits
			  << ";withdrawal:" << _nbWithdrawals << std::endl;
}


