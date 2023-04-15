# Golestan 

the teacher and student part of the project are still remaining
I will describe some of the functions here

### login()
the login function will read all users and save the data from files to a linked list called "user"
after saving the data to the linked list, it will get Id and password from user and will check it from the linked list and if both are correct the user will be logged in
the functions will return the pointer to the user structure

### main()
the main function will get the logged in user's data and will referrence each type of user to it's function

### admin()
the admin function will get input and referrence to each function
admin has 3 chioce, 1.add new calss 2.edit users 3.exit
### new_class()
this function is to add new classes, will ask the class name, class id, teacher's name and teacher's id from admin and will add to a linked list, and then will write it to a file to be saved
### edit_users()
just a simple function to change user's passwords
