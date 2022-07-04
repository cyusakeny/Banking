#include "usercrud.cpp"
#include "accountcrud.cpp"
void InsertUser(){
    User user;
    cout<<"Create user"<<endl;
    cout <<"id: ";
    cin>>user.id;
    cout<<"\nUsername:";
    cin>>user.username;
    cout<<"\nfullname:";
    cin>>user.fullname;
    cout<<"\nemail:";
    cin>>user.email;
    cout<<"\nphone:";
    cin>>user.phone;
    cout<<"\ngender:";
    cin>>user.gender;
    cout<<"\nnationalid:";
    cin>>user.national_id;
    user.created_at=time(NULL);
    createUser(user);
}
void updateUser(){
    string nationalid;
    cout<<"Update user\n";
    cout<<"Enter your national Id:";
    cin>>nationalid;
    User user = getUser(nationalid);
    if (user.national_id.length()==0)
    {
        cout<<"User non existing \n";
    }
    else{
    cout<<"\nUsername:";
    cin>>user.username;
    cout<<"\nfullname:";
    cin>>user.fullname;
    cout<<"\nemail:";
    cin>>user.email;
    cout<<"\nphone:";
    cin>>user.phone;
    cout<<"\ngender:";
    cin>>user.gender;
    updateUser(user);
    }
}
void deleteUserfnc()
 {
     cout << "Delete User\n";
     cout << "Enter national id :";
     string national_id;
     cin >> national_id;
     User user = getUser(national_id);
     if (user.national_id.length())
     {
         cout << "User not found\n";
     }
     else
     {
         cout << "User found\n";
         deleteUser(user.id);
     }
 }
    void getUserfnc()
    {
        cout << "Get User\n";
        cout << "Enter national id :";
        string national_id;
        cin >> national_id;
        User user = getUser(national_id);
        if (user.national_id.length())
        {
            cout << "User not found\n";
        }
        else
        {
            cout << "User found\n";
            cout << "User id :" << user.id << endl;
            cout << "Username :" << user.username << endl;
            cout << "Full name :" << user.fullname << endl;
            cout << "Email :" << user.email << endl;
            cout << "Phone :" << user.phone << endl;
        }
    }
    void createAccount(){
        cout << "Create Account\n";
        cout << "Enter national id :";
        string national_id;
        cin >> national_id;
        User user = getUser(national_id);
        if (user.national_id.length() == 0)
        {
            cout << "User not found\n";
        }
        else{
            BankAccount account;
              cout << "Enter id :";
              cin>>account.id;
             cout << "\nEnter account code :";
              cin >> account.account_code;
            account.balance= 10;
            account.user_id = user.id;
            createAccount(account);
            cout << " \nAccount created";
        }
    }
    void Deposit(){
          cout << "Deposit on Account\n";
        cout << "Enter account_code :";
        string account_code;
        cin >> account_code;
        BankAccount account = getAccount(account_code);
        if (account.account_code.length() == 0)
        {
            cout << "Account not found\n";
        }
        else{
            int amount;
            cout << "Enter amount to deposit: ";
            cin >> amount;
            account.balance = account.balance + amount;
             updateAccount(account);
            cout << "\nMoney on account";
        }
    }

int main(){
    // createAccount();
Deposit();
}