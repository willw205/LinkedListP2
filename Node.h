
 //Creator: Emily Yarvis
 //Date: 1/17/23
 //The Header for Node Class

 #include <iostream>
 #include "Student.h"

 using namespace std;

 class Node {

  public:
   Node(Student* newStudent);
   ~Node();
   Node* getNext();
   Student* getStudent();
   void setNext(Node* newNext);

  private:
   Node* next;
   Student* student;
   
 };
 
