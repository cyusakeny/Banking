#include"bank.cpp"
#include <fstream>
#include <vector>
int createAccount(BankAccount account){
 ofstream file_obj;
   file_obj.open("Account.txt", ios::app);
   if (
     file_obj<<account.id<<'|'<<account.user_id<<'|'<<account.account_code<<'|'
     <<account.balance<<'\n'
   )
   {
    file_obj.close();
    return 1;
   }
   else{
    file_obj.close();
    return 0;
   }  
}
BankAccount ChangeFromStringToAccount(string filedata){
BankAccount account;
size_t pos = 0;
string token;
int dataposition = 0;
while ((pos = filedata.find("|")) != std::string::npos) {
    token = filedata.substr(0, pos);
    if (dataposition ==0)
    {
        account.id = stoi(token);
    }

    else if(dataposition==1){
        account.user_id =stoi(token);
    }
    else if(dataposition==2){
        account.account_code =token;  
    }
    dataposition++;
     filedata.erase(0, pos + 1);
}   
 account.balance=stoi(filedata);
return account;
}
vector<BankAccount> getAllAccounts(){
    vector<BankAccount> accounts;
    ifstream myfile;
    myfile.open("Account.txt",ios::in);
    if (!myfile)
    {
         myfile.close();
       return vector<BankAccount>();
    }
    else{
        string filedata;
        while ( getline(myfile,filedata))
        {   if(filedata.length()==0)continue;
            accounts.push_back(ChangeFromStringToAccount(filedata));
        }
        myfile.close();
        return accounts;
    }
}
BankAccount getAccount(string accountCode){
    vector<BankAccount> accounts = getAllAccounts();
    BankAccount nullaccount;
    for(const auto& account : accounts){
        if (account.account_code.compare(accountCode)==0)
        {
            return account;
        }
    }
    return nullaccount;
}
BankAccount getAccountByUser(int userId){
      vector<BankAccount> accounts = getAllAccounts();
    BankAccount nullaccount;
    for(const auto& account : accounts){
        if (account.user_id==userId)
        {
            return account;
        }
    }
    return nullaccount;
}
void updateAccount(BankAccount updatedaccount){
     ofstream file_obj;
     vector<BankAccount> accounts = getAllAccounts();
     file_obj.open("Account.txt");
      for(const auto& account : accounts){
        if (account.id==updatedaccount.id)
        {
             file_obj<<updatedaccount.id<<'|'<<updatedaccount.user_id<<'|'<<updatedaccount.account_code<<'|'
     <<updatedaccount.balance<<'\n';
        }
        else{
            cout<<"\nBalance:"<<account.balance;
 file_obj<<account.id<<'|'<<account.user_id<<'|'<<account.account_code<<'|'<<account.balance<<'\n';
        }
    }
    file_obj.close();
}
void deleteAccount(int id){
 ofstream file_obj;
     vector<BankAccount> accounts = getAllAccounts();
     file_obj.open("Account.txt");
      for(const auto& account : accounts){
        if (account.id==id)
        {
           continue;
        }
        else{
  file_obj<<account.id<<'|'<<account.user_id<<'|'<<account.account_code<<'|'
     <<account.balance<<'\n';
        }
    }
    file_obj.close();
}