#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>
#include <vector>
#include "Bank.hpp"

struct Bank;


struct Account {

	private:
		int id;
		int value;
		int loan;
		Account();
		friend struct Bank;
		Account(int idClient, size_t deposit);

	public:

		// void setValue(int );
		// const int &getId() const;
		friend std::ostream& operator << (std::ostream& p_os, const Account& p_account)
		{
			p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
			return (p_os);
		}
};

Account::Account(int idClient, size_t deposit) : id(idClient), value(deposit), loan(0) {}




#endif