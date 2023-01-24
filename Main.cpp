
 //William Wong
 //1/24/23
 //This project is linked list, allowing an individual to store students and add, print, delete, and/average

 #include <iostream>
 #include <iomanip>
 #include <cstring>
 #include "Student.h"
 #include "Node.h"
 using namespace std;

 //Defining the functions


 int main() {

   //Initialization

   Node* head = NULL;
   char input[100];
   bool running = true;

    while(running == true){
      
      cout << " " << endl;
      cout << "Please Choose An Option (ADD/PRINT/DELETE/AVERAGE/QUIT)" << endl; 
      cin >> input;
      
      if(strcmp(input, "PRINT") == 0){

      }
      else if(strcmp(input, "ADD") == 0){ //New student is created below
       
       Student* newStudent = new Student();
       cout << "Please Enter First Name: " << endl;
       cin >> newStudent->getFirstName();
       cout << "Please Enter Last Name: " << endl;
       cin >> newStudent->getLastName();
       cout << "Please Enter Student ID: " << endl;
       cin >> *newStudent->getID();
       cout << "Please Enter GPA: " << endl;
       cin >> *newStudent->getGPA();
       ADD(head, head, newStudent);
     }
     else if(strcmp(input, "DELETE") == 0){
       //Allow user to search ID to remove from list
       cout << "Please Enter ID to Remove: " << endl;
       int id;
       cin >> id;

     }
     else if(strcmp(input, "AVERAGE") == 0){
       //Helps to average all the GPAS

     }
     else if(strcmp(input, "QUIT") == 0){
       //Allows user to quit the program 
       cout << "Thanks for using this Linked List Program Today! Hope to see you soon!" << endl;
       break;
     }
     else{
       //Tells user that their input is invalid
       cout <<"Unidentifiable! ALL CAPS PLEASE!" << endl;
     }
   }
    return 0;
 }

 //Below, student is added to linked list

 void ADD(Node* &head, Node* &current, Student* newStudent){

   //Checks if list is empty

   if(current == NULL){
     current = new Node(newStudent);
   }
   else if(current == head && *(current->getStudent()->getID()) > *(newStudent->getID())){
     Node* temp = head;
     head = new Node(newStudent);
     head->setNext(temp);
   }
   //Below checks if at the end
   else if(current->getNext() == NULL){
     Node* lastNode = new Node(newStudent);
     current->setNext(lastNode);
   }
   //Below helps to reorganize list based off of ID (least to greatest)
   else if(*(current->getNext()->getStudent()->getID()) > *(newStudent->getID())){
     Node* temp = new Node(newStudent);
     temp->setNext(current->getNext());
     current->setNext(temp);
   }
   else{
     //Below just keeps recursing
     Node* temp = current->getNext();
     ADD(head, temp, newStudent);
   }
 }

