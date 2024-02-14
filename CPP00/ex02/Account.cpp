#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";created" << std::endl;
	this->_nbAccounts++;
	this->_totalAmount += this->_amount;
}

Account::~Account()
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";closed" << std::endl;
}

void Account::_displayTimestamp(void)
{
	std::time_t const timer = std::time(NULL);
	std::tm const *timeinfo = std::localtime(&timer);
	char timestamp[19];

	std::strftime(timestamp, 19, "[%Y%m%d_%H%M%S] ", timeinfo);
	std::cout << timestamp;

	return;
}

void	Account::makeDeposit(int deposit) 
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << (this->_amount += deposit);
	std::cout <<  ";nb_deposits:" << ++this->_nbDeposits << std::endl;
    ++Account::_totalNbDeposits;
    Account::_totalAmount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal) 
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	if (this->_amount < withdrawal) 
    {
		std::cout << ";withdrawal:refused" << std::endl;
        return false;
	}
	this->_nbWithdrawals++;
	this->_amount -= withdrawal;
	std::cout << ";withdrawal:" << withdrawal;
	std::cout << ";amount:" << this->_amount;
	std::cout <<  ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    ++Account::_totalNbWithdrawals;
    Account::_totalAmount -= withdrawal;
	return true;
}

int     Account::checkAmount(void) const
{
    return this->_amount;
}

void	Account::displayStatus(void) const 
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

int Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts;
    std::cout << ";total:" << Account::_totalAmount;
    std::cout << ";deposits:" << Account::_totalNbDeposits;
    std::cout << ";withdrawals:" << Account::_totalNbWithdrawals;
    std::cout << std::endl;
}

