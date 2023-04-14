#include <iostream>
#include <fstream>
using namespace std;

struct user{
    string role;
    string first_name;
    string last_name;
    string username;
    string password;
    user *nxt;
};

user* login();
void admin();
void teacher();
void student();

int main() {
    user *logged_in = login();
    switch(logged_in->role){
    	case 0: //admin
    		admin();
    		break;
    	case 1: //teacher
    		teacher();
    		break;
    		
    	case 2: //student
    		student();
    		break;	
		}
    return 0;
}


user* login(){
	//READ USERS FROM FILE
    ifstream users("Users.txt");
    string role;
    string first_name;
    string last_name;
    string username;
    string password;
    user *curr, *head;
    head = NULL;
    while(users >> role >>  first_name >> last_name >> username >> password){
    	curr = new struct user;
        curr->role = role;
        curr->first_name = first_name;
        curr->last_name = last_name;
        curr->username = username;
        curr->password = password;
        curr->nxt = head;
        head = curr;
	}
	//LOGIN
	curr = head;	
	for(int i =0; i<=3; i++){
		if(i == 3){
			break;
		}
    	cout<<"Welcome, Please Enter Username: ";
    	cin>>username;
    	cout<<"Please Enter Password: ";
    	cin>>password;
    	while(curr != NULL){
    		if(username == curr->username && password == curr->password){
    			cout<<"Login successfull!\n";
    			return curr;
			}
			curr = curr->nxt;
		}
		cout<<"Login Failed\n";
		return NULL;
	}
}