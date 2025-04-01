#include "Bank.hpp"
#include "Account.hpp"

/*
• The bank must receive 5% of each money inflow on these client accounts
• The accounts must never have two identical IDs
• The attributes of the structures must not be modifiable from the outside
• The bank must be able to create, delete and modify the accounts of these customers
• The bank must be able to give a loan to a customer, within the limits of its funds
• It must be impossible to add money to a client account without going through the
bank
• If it makes sense, the creation of a Getter and a Setter is mandatory. Getter(s) by
copy will not be accepted
• If it makes sense, the creation of a const Getter is mandatory. const Getter(s) by
copy will not be accepted
*/

int main(void) {
	Bank SociteG;

	SociteG.CreateAccount(100);
	SociteG.CreateAccount(-1);
	SociteG.CreateAccount(0);

	// check
	SociteG.CreateAccount(500);
	SociteG.CreateAccount(60);
	SociteG.DeleteAccount(1);
	SociteG.DeleteAccount(2);
	SociteG.DeleteAccount(3);
	SociteG.inflow(2, 15000);
	SociteG.outflow(1, 200);
	SociteG.giveLoan(9, 100);
	std::cout << SociteG << std::endl;
	
	// Account lol(15, 1000);
}