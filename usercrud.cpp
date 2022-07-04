#include"user.cpp"
#include <fstream>
#include <vector>
int createUser(User user){
   ofstream file_obj;
   file_obj.open("User.txt", ios::app);
   if (
     file_obj<<user.id<<'|'<<user.fullname<<'|'<<user.username<<'|'<<user.email<<'|'
   <<user.phone<<'|'<<user.gender<<'|'<<user.national_id<<'|'<<user.created_at<<endl
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
User ChangeFromStringToUser(string filedata){
User user;
size_t pos = 0;
string token;
int dataposition = 0;
while ((pos = filedata.find("|")) != std::string::npos) {
    token = filedata.substr(0, pos);
    if (dataposition ==0)
    {
        user.id = stoi(token);
    }

    else if(dataposition==1){
        user.fullname =token;
    }
    else if(dataposition==2){
        user.username =token;
    }
    else if(dataposition==3){
        user.email =token;
    }
    else if(dataposition==4){
        user.phone = stoi(token);
    }
    else if(dataposition==5){
        user.gender =token;
    }
    else if(dataposition==6){
        user.national_id =token;
    }
    dataposition++;
     filedata.erase(0, pos + 1);
}
     return user;
}
vector<User> getAllUsers(){
    vector<User> users;
    ifstream myfile;
    myfile.open("User.txt",ios::in);
    if (!myfile)
    {
         myfile.close();
       return vector<User>();
    }
    else{
        string filedata;
        while (getline(myfile,filedata)){
            if(filedata.length()==0) continue;
            users.push_back(ChangeFromStringToUser(filedata));
        }
        myfile.close();
        return users;
    }
}
User getUser(string userNID){
    vector<User> Allusers = getAllUsers();
    User nullUser;
    for(const auto& user : Allusers){
        if (user.national_id.compare(userNID)==0)
        {
            return user;
        }
    }
    return nullUser;
}
void updateUser(User updatedUser){
     ofstream file_obj;
     vector<User> users = getAllUsers();
     for(const auto& user : users){
        cout<<"User: "<<user.fullname<<endl;
     }
     file_obj.open("User.txt");
      for(const auto& user : users){
        if (user.id==updatedUser.id){
            file_obj<<updatedUser.id<<'|'<<updatedUser.fullname<<'|'<<updatedUser.username<<'|'<<updatedUser.email<<'|'<<updatedUser.phone<<'|'<<updatedUser.gender<<'|'<<updatedUser.national_id<<'|'<<updatedUser.created_at<<"\n" ;
        }else {
            file_obj<<user.id<<'|'<<user.fullname<<'|'<<user.username<<'|'<<user.email<<'|'<<user.phone<<'|'<<user.gender<<'|'<<user.national_id<<'|'<<user.created_at <<"\n";
        }
    }
    file_obj.close();
}
void deleteUser(int id){
 ofstream file_obj;
     vector<User> users = getAllUsers();
     file_obj.open("User.txt");
      for(const auto& user : users){
        if (user.id==id)
        {
           continue;
        }
        else{
file_obj<<user.id<<'|'<<user.fullname<<'|'<<user.username<<'|'<<user.email<<'|'
   <<user.phone<<'|'<<user.gender<<'|'<<user.national_id<<'|'<<user.created_at <<"\n";
        }
    }
    file_obj.close();
}
