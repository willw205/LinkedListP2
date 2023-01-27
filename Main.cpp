
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

 void ADD(Node* &head, Node* &current, Student* newStudent);
 void PRINT(Node* head, Node* next);
 void DELETE(Node* head, Node* &current, int id);
 void AVERAGE(Node* head);
 void averageTakeIn(Node* current, double&sum, int & count);


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
        PRINT(head, head);
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
       DELETE(head, head, id);

     }
     else if(strcmp(input, "AVERAGE") == 0){
       //Helps to average all the GPAS
       AVERAGE(head);

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

 //Below helps to print the list

 void PRINT(Node* head,Node* next){
   if(next == head){
     cout << "Students: " << endl;
   }
   //All the information of the students are printed out!
   if(next != NULL){
     cout << next->getStudent()->getFirstName() << " " << next->getStudent()->getLastName() << " " << *(next->getStudent()->getID()) << " " << fixed << setprecision(2) << *(next->getStudent()->getGPA()) << endl;
     PRINT(head,next->getNext());
   }
 }

 //Below helps to delete node from list

 void DELETE(Node* head,Node* &current, int id){
   //Checks if there is an empty list
   if(head == NULL){
     cout<< "No students as of now!"<<endl;
   }
   else if(head == current && id == *(current->getStudent()->getID())){
     //Checks if first student
     cout << "Deleting numero uno Studente!" << endl;
     Node* createHead = current->getNext();
     current->~Node();
     current = createHead;
   }
   else if(current->getNext() == NULL){
     //Checks if at end of the list
     cout << "No ID Found!" << endl;
   }
   else if(*(current->getNext()->getStudent()->getID()) == id){
     //Makes sure to check for the same ID
     cout << "beep... beep... deleting the student: " << *(current->getNext()->getStudent()->getID()) << endl;
     Node* nextN = current->getNext()->getNext();
     current->getNext()->~Node();
     current->setNext(nextN);
   }
   else{
     //Keeps on recursing!
     Node* next = current->getNext();
     DELETE(head, next, id);
   }
 }

 //Below helps to average GPA

 void AVERAGE(Node* head) {

   if (head == NULL) {
     cout << "No students as of Now!" << endl;
     return;
   }

   //Initializing variable 
   
   double sum = *(head->getStudent()->getGPA());
   int count = 1;

   //Below passes the next node in list as references
   
   averageTakeIn(head->getNext(), sum, count);
   cout << fixed << setprecision(2) << "The AVERAGE GPA: " << sum / count << endl;
   
 }

 //Recursive Function Below

 void averageTakeIn(Node* current, double &sum, int &count) {

   if (current == NULL) {
   return;
   }

   //Adss gpa of student at Node to sum variable
   
   sum += *(current->getStudent()->getGPA());
   count++;
   averageTakeIn(current->getNext(), sum, count);
   
}
