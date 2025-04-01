#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include <vector>
#include "Account.hpp"

// Je ne verifie pas les over et under flow des deposite

static int ERROR = 0;

struct Bank
{
	private:
		int liquidity;
		std::vector<Account *> clientAccounts;
		Bank(Bank&);
		Bank &operator=(const Bank&);

	public:
		Bank();
		~Bank();
	
		int CreateAccount(int deposit);
		const int &getbalance(int) const ;
		void DeleteAccount(int);
		
		void giveLoan(int, int);

		void inflow(int, int);
		void outflow(int, int);

		friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
		{
			p_os << "Bank informations : " << std::endl;
			p_os << "Liquidity : " << p_bank.liquidity << std::endl;
		for (std::vector<Account *>::const_iterator it = p_bank.clientAccounts.begin(); it != p_bank.clientAccounts.end() ;++it)
				p_os << *it << std::endl;
			return (p_os);
		}
};


Bank::Bank() : liquidity(0) {}

Bank::~Bank() {
	for (std::vector<Account *>::const_iterator it = clientAccounts.begin(); it != clientAccounts.end() ;++it) {
		delete *it;
	}
}

int Bank::CreateAccount(int deposit) {
	if (deposit <= 0) {
		std::cerr << "Bank Alerts: Wrong deposit, fail to creat account\n";
		return (0);
	}
	int id = 0;
	if (clientAccounts.size() == 0)
		id = 1;
	else 
		id = clientAccounts.back()->id + 1;
	this->liquidity += (deposit * .05);
	Account* NewClients = new Account(id, deposit * .95);
	clientAccounts.push_back(NewClients);
	std::cout << "Bank: New client added with the id: " << id << " and a deposit of: " << deposit << "\n"; 
	return (id);
}

// factoriser en faisant une focntion getclients

const int &Bank::getbalance(int id) const { 
	for (std::vector<Account *>::const_iterator it = clientAccounts.begin(); it != clientAccounts.end() ;++it) {
		if (id == (*it)->id) {
			return ((*it)->value);
		}
	}
	std::cerr << "Bank Alerts: Unknown client\n";
	return (ERROR);
}

void Bank::DeleteAccount(int id) {
	for (std::vector<Account *>::iterator it = clientAccounts.begin(); it != clientAccounts.end() ;++it) {
		if (id == (*it)->id) {
			delete (*it);
			clientAccounts.erase(it);
			return ;
		}
	}
	std::cerr << "Bank Alerts: Unknom client\n";
}


void Bank::inflow(int id, int amounts) {
	if (amounts <= 0) {
		std::cerr << "Bank Alerts: Negatifs inflow\n";
		return ;
	}
	for (std::vector<Account *>::iterator it = clientAccounts.begin(); it != clientAccounts.end() ;++it) {
		if (id == (*it)->id) {
			(*it)->value += amounts * .95;
			liquidity += amounts * .05;
			return ;
		}
	}
	std::cerr << "Bank Alerts: Unknom client\n";
}

void Bank::outflow(int id, int amounts) {
	if (amounts <= 0) {
		std::cerr << "Bank Alerts: Negatifs outflow\n";
		return ;
	}

	for (std::vector<Account *>::iterator it = clientAccounts.begin(); it != clientAccounts.end() ;++it) {
		if (id == (*it)->id) {
			if ((*it)->value - amounts >= 0)
			{
				std::cout << (*it)->value << "  " << amounts << " " << (*it)->value - amounts  << std::endl;
				(*it)->value -= amounts;
			}
			else
				std::cout << "Bank Alerts: not enough to make a withdraw or paiments" << std::endl;
			return;
		}
	}
	std::cerr << "Bank Alerts: Unknom client\n";
}

void Bank::giveLoan(int id, int amounts) {
	if (amounts <= 0) {
		std::cerr << "Bank Alerts: Negatifs loan\n";
		return ;
	} else if (liquidity - amounts < 0) {
		std::cerr << "Bank Alerts: None loan for you\n";
		return;
	}
	for (std::vector<Account *>::iterator it = clientAccounts.begin(); it != clientAccounts.end() ;++it) {
		if (id == (*it)->id) {
			(*it)->loan += amounts;
		}
	}
	std::cerr << "Bank Alerts: Unknom client\n";
}


#endif