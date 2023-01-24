 //Creator: Emily Yarvis
 //Date: 1/17/23
 //Node Class

 #include "Node.h"

 Node::Node(Student* newStudent) {
   theStudent = newStudent;
   next = NULL;
 }

 Node::~Node() {
   delete theStudent;
   next = NULL;
 }

 void Node::setNext(Node* nextNode) {

   next = nextNode;
 }


 Node* Node::getNext() {
   return next;
 }

 Student* Node::getStudent() {
   return student;
 }

 
