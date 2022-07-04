#include<iostream>
using namespace std;
// Details transactions on Account
class Transaction{
	public:
        int id;
        transaction_type type;
        char account_code[10];
        int to ;
        int from;
        int amount;
};