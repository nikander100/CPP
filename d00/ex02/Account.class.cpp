/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Account.class.cpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/07 14:48:30 by nvan-der      #+#    #+#                 */
/*   Updated: 2021/10/07 15:51:24 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.class.hpp"

Account::Account(void)
{}

Account::Account(int initial_deposit)
{
	int	_nbAccounts = 0;
	int	_totalAmount = 0;
	int	_totalNbDeposits = 0;
	int	_totalNbWithdraws = 0;

	_totalAmount += initial_deposit;
	_nbAccounts += 1;

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


int	Account::getNbAccounts(void) 
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
	<< ";total:" << _totalAmount
	<< ";deposits:" << _totalNbDeposits
	<< ";witdrawawls" << _totalNbWithdrawals << std::endl;
}