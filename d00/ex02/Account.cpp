/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Account.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/07 14:48:30 by nvan-der      #+#    #+#                 */
/*   Updated: 2021/10/08 18:05:55 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

Account::Account(void):_amount(0),_nbDeposits(0),_nbWithdrawals(0)
{
	_accountIndex = getNbAccounts();
}

Account::Account(int initial_deposit):_amount(initial_deposit),_nbDeposits(0),_nbWithdrawals(0)
{
	_accountIndex = getNbAccounts();
	_totalAmount += initial_deposit;
	++_nbAccounts;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	<< ";amount:" << _amount
	<< ";created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	<< ";amount:" << _amount
	<< ";closed" << std::endl;
	
}

int		Account::getNbAccounts(void) 
{
	return _nbAccounts;
}

int		Account::getTotalAmount(void)
{
	return _totalAmount;
}

int		Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int		Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
	<< ";total:" << _totalAmount
	<< ";deposits:" << _totalNbDeposits
	<< ";witdrawawls" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_amount += deposit;
	++_nbDeposits;

	_totalAmount += deposit;
	++_totalNbDeposits;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	<< ";p_amount:" << _amount - deposit
	<< ";deposit:" << deposit
	<< ";amount" << _amount 
	<< ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (withdrawal <= _amount)
	{
		_amount += withdrawal;
		++_nbWithdrawals;

		_totalAmount -= withdrawal;
		++_totalNbWithdrawals;
		
		_displayTimestamp();
		std::cout << "index:" << _accountIndex
		<< ";p_amount:" << _amount + withdrawal
		<< ";withdrawal:" << withdrawal
		<< ";amount" << _amount 
		<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return true;
	}
	else
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex
		<< ";p_amount:" << _amount + withdrawal
		<< ";withdrawal:refused" << std::endl;
		return false;
	}
}

int		Account::checkAmount(void) const
{
	return _amount;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	<< ";amount:" << _amount
	<< ";deposits:" << _nbDeposits
	<< ";withdrawals" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::cout << "[19920104_091532]";
}
