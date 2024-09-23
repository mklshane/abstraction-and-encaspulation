#include <iostream>
#include <limits>
using namespace std;

// Function to get validated integer input from the user
double getValidatedInput(const string prompt) {
    double input;
    cout << prompt;
    while (!(cin >> input)) {  
        cin.clear();  
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        cout << "   Invalid input. Input a number. \n\n" << prompt;
    }
    cin.ignore();  
    return input;
}

class Account {
	private:
		double deposit;
		double balance;
	public: 
		Account() : deposit(0), balance(0) {} 

		// Getter functions to access deposit and balance
		double getDeposit() { return deposit; }
		double getBalance() { return balance; }

		// Virtual functions for deposit, withdraw, and balance checks
		virtual void depositMoney(double depo) = 0;
		virtual void withdrawMoney(double amount) = 0;
		virtual void checkBalance() = 0;

		// Setter function for deposit with validation
		void setDeposit(double depo) {
			if (depo <= 0) { 
				cout << "\n   Deposit money must be more than zero." << endl;
			}
			else {
				deposit = depo;
				balance += deposit; 
				cout << "   Deposited money: " << deposit << endl;
				cout << "   Current balance: " << balance << endl;
			}	
		}
		// Setter function for balance
		void setBalance(double newBalance) {
			balance = newBalance;
		}
};

// Derived class for SavingsAccount
class SavingsAccount : public Account {
	public: 
		// Override depositMoney function
		void depositMoney(double depo) override {
			setDeposit(depo); 
		}
		
		// Override withdrawMoney function with a minimum balance requirement
		void withdrawMoney(double amount) override {
			if (getBalance() < amount || (getBalance() - amount) < 1000) {
				cout << "   Insufficient funds! Minimum balance should be 1000." << endl;
			} else {
				setBalance(getBalance() - amount);  
				cout << "   Withdrawn: " << amount << endl;
				cout << "   Current balance: " << getBalance() << endl;
			}
		}
		
		// Override checkBalance function
		void checkBalance() override {
			if (getBalance() <= 0) {
				cout << "\n   No balance yet. Deposit money.\n";
			} else {
				cout << "   Current Balance: " << getBalance() << endl;
			}
		}
};

// Derived class for CurrentAccount
class CurrentAccount : public Account {
	public: 
		// Override depositMoney function
		void depositMoney(double depo) override {
			setDeposit(depo);  
		}
		
		// Override withdrawMoney function without minimum balance constraint
		void withdrawMoney(double amount) override {
			if (getBalance() < amount) {
				cout << "   Insufficient funds!" << endl;
			} else {
				setBalance(getBalance() - amount);  
				cout << "   Withdrawn: " << amount << endl;
				cout << "   Current balance: " << getBalance() << endl;
			}
		}
		
		// Override checkBalance function
		void checkBalance() override {
			if (getBalance() <= 0) {
				cout << "\n   No balance yet. Deposit money.\n"; }
				else {
				cout << "   Current Balance: " << getBalance() << endl;
		}
		}
};

int main() {
	int account, savings, current; 
	double deposit, withdraw; 
	SavingsAccount save; 
	CurrentAccount currAcc;   
	
	do { 
		cout << "\t MAIN MENU \n\n";
		cout << "   1 - Savings Account \n";
		cout << "   2 - Current Account \n";
		cout << "   3 - Exit \n";
		account = getValidatedInput("   Enter your choice [1-3]: ");  
	
		switch (account) {
			// Savings account menu
			case 1: {
				do {
					system("CLS");
					cout << "\t Savings Account \n";
					cout << "   1 - Deposit\n";
					cout << "   2 - Withdraw\n";
					cout << "   3 - Check Balance\n";
					cout << "   4 - Back\n";
					savings = getValidatedInput("   Enter your choice [1-4]: ");  
					
					switch (savings) {
						case 1: {
							cout << "\n\tDEPOSIT\n";
							do {
								deposit = getValidatedInput("\n   Enter amount to deposit: P "); 
								if ((save.getBalance() + deposit) < 1000) {
									cout << "   Current Balance is less than 1000, please enter a higher amount.\n";
								}
							} while ((save.getBalance() + deposit) < 1000);  
							save.depositMoney(deposit); 
							break;
						}
						case 2: {
							cout << "\n\tWITHDRAW\n";
							if(save.getBalance()==0){
							save.checkBalance();  }
							else {
							withdraw = getValidatedInput("\n   Enter amount to withdraw: P ");  
							save.withdrawMoney(withdraw); }
							break;
						}
						case 3: {
							cout << "\n\tCHECK BALANCE\n";
							save.checkBalance();  
							break;
						}
						case 4: {
							cout << "\n    Returning to main menu...\n";
							break;  
						}
						default: {
							cout << "\n   Invalid choice";
							break;
						}
					}
					cout << endl;
					system("PAUSE");  
					system("CLS");  
				} while (savings != 4);  
				break;
			}
			
			// Current account menu
			case 2: {
				do {
					system("CLS");
					cout << "\t Current Account \n";
					cout << "   1 - Deposit\n";
					cout << "   2 - Withdraw\n";
					cout << "   3 - Check Balance\n";
					cout << "   4 - Back\n";
					current = getValidatedInput("   Enter your choice [1-4]: ");  
					
					switch (current) {
						case 1: {
							cout << "\n\tDEPOSIT\n";
							deposit = getValidatedInput("\n   Enter amount to deposit: P ");  
							currAcc.depositMoney(deposit);  
							break;
						}
						case 2: {
							cout << "\n\tWITHDRAW\n";
							if(save.getBalance()==0){
							save.checkBalance();  }
							else {
							withdraw = getValidatedInput("\n   Enter amount to withdraw: P ");  
							save.withdrawMoney(withdraw); }
							break;
						}
						case 3: {
							cout << "\n\tCHECK BALANCE\n";
							currAcc.checkBalance();  
							break;
						}
						case 4: {
							cout << "\n    Returning to main menu...\n";
							break; 
						}
						default: {
							cout << "\n   Invalid choice";
							break;
						}
					}
					cout << endl;
					system("PAUSE"); 
					system("CLS");  
				} while (current != 4); 
				break;
			}
			
			// Exit the program
			case 3: {
				cout << "\n   Exiting program...";
				return 0;
			}
			default: {
				cout << "\n   Invalid choice\n\n";
				break;
			}
		}
	} while (account != 3);  
	return 0;
}
