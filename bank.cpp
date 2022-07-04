#include <iostream>
#include<ctime>
using namespace std;
enum transaction_type{
    deposit,
    withdraw,
    sending,
    receiving
};


// Details of Account of the User
class BankAccount{
	public:
        int id;
        int user_id;
        string account_code;
        int balance;
};
