
 //Written By: Emily Yarvis                                                                     
 //Date: 1/17/24                                                                                
 //Header for Node class

 #ifndef NODE
 #define NODE

 #include<iostream>
 #include "Student.h"


 class Node {
  public:
   Node(Student* newStudent);//node constructor
   ~Node();//node destructor
   void setNext(Node* nextNode);//sets a nodes next node
   Node* getNext();//gets a nodes next node
   void setPrevious(Node* nextNode);//sets a nodes previous node
   Node* getPrevious();//gets a nodes previous node
   Student* getStudent();//gets the student associated with the node
  private:
   Node* next;//the nodes next node
   Student* theStudent;//the nodes associated student
   Node* previous;//the nodes previous node
 };
 #endif
