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
struct lesson{
	string class_name;
	string calss_id;
	string teacher_fname;
	string teacher_lname;
	string teacher_id;
	//user *student;
	lesson *nxt;
};


user* login();
void admin();
void teacher();
void student();
void new_class();
void edit_users();

int main() {
    user *logged_in = login();
    if(logged_in->role == "0"){
    	admin();
	}
	else if(logged_in->role == "1"){
		cout<<"_____________________TEACHER_____________________";
	}
	else if(logged_in->role == "2"){
		cout<<"_____________________STUDENT_____________________";
	}
	else{
		cout<<"EROR!";
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
    user *curr;
	user *head = NULL;
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
	}
    cout<<"Login Failed\n";
	return NULL;
}


	
void edit_users(){
	ifstream users("Users.txt");
    string role;
    string first_name;
    string last_name;
    string username;
    string password;
	user *curr;
	user *head = NULL;
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
	int i=1;
	while(curr != NULL){
		cout<<i<<"."<<curr->username<<"\t"<<curr->password<<endl;
		i++;
		curr = curr->nxt;
	}
	cout<<"enter the username you want to edit (enter 0 to exit) \n";
	string user_to_edit;
	cin>>user_to_edit;
	if(user_to_edit == "0"){
		return;
	}
	cout<<"Enter the new password: ";
	string new_pass;
	cin>>new_pass;
	curr = head;
	while(curr != NULL){
		if(curr->username == user_to_edit){
			curr->password = new_pass;
		}
		curr = curr->nxt;
	}
	//SAVE TO FILE
	ofstream users_output("Users.txt");
	curr = head;
	while(curr!= NULL){
        users_output<<curr->role<<" "<<curr->first_name<<" "<<curr->last_name<<" "<<curr->username<<" "<<curr->password;
        curr = curr->nxt;
        if(curr!= NULL)
            users_output<<endl;
    }
	//DELETE MEMORY
	while(head!= NULL){
        curr = head->nxt;
        delete head;
        head = curr;
    }
    head = NULL;
}

void new_class(){
    lesson *Head = NULL;
    lesson *curr;

    ifstream Classes("Classes.txt");
    string class_name;
    string class_id;
    while(Classes >> class_name >>class_id){
        curr = new lesson;
        curr->nxt = Head;
        Head = curr;
    }
    
    curr = new lesson;
    cout<<"Enter Calss Name : ";
    cin>>curr->class_name;
    cout<<"Enter Class ID: ";
    cin>>curr->calss_id;
    ifstream users("Users.txt");
    string role;
    string first_name;
    string last_name;
    string username;
    string password;
	user *tmp;
	user *head = NULL;
    while(users >> role >>  first_name >> last_name >> username >> password){
    	tmp = new user;
        tmp->role = role;
        tmp->first_name = first_name;
        tmp->last_name = last_name;
        tmp->username = username;
        tmp->password = password;
        tmp->nxt = head;
        head = tmp;
	}
	int i=1;
	while(tmp != NULL){
		if(tmp->role == "1"){
			cout<<i<<"."<<tmp->username<<"\t"<<tmp->first_name<<"\t"<<tmp->last_name<<endl;
			i++;
		}
		tmp = tmp->nxt;
	}
	cout<<"Enter Class teacher's username: ";
	cin>>curr->teacher_id;
	cout<<"Enter Class teacher's first name: ";
	cin>>curr->teacher_fname;
	cout<<"Enter Class teacher's last name: ";
	cin>>curr->teacher_lname;
    curr->nxt = Head;
    Head = curr;

    cout<<"Class Added.\n";
    cout<<"Class Name : "<<curr->class_name<<"\nClass ID : "<<curr->calss_id<<endl;



    curr = Head;
    ofstream out_class("Classes.txt");
    while(curr!= NULL){
        out_class<<curr->class_name<<" "<<curr->calss_id;
        curr = curr->nxt;
        if(curr!= NULL)
            out_class<<endl;
    }

    while(Head!= NULL){
        curr = Head->nxt;
        delete Head;
        Head = curr;
    }
}

void admin(){
	int toDo = -1;
	while(toDo != 0){
		cout<<"___________________ADMIN___________________\n";
		cout<<"Please Enter what do you want to do? \n";
		cout<<"1.New Class \n2.Edit users\n0.exit\n";
		cin>>toDo;
		switch(toDo){
			case 1:
				new_class();
				break;
			case 2:
				edit_users();
				break;
			case 0:
				break;
		}
	}
}


