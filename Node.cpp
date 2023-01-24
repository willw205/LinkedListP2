
 //Written By: Emily Yarvis
 //Date: 1/17/24
 //Body of the Node Class

 #include<iostream>
 #include "Node.h"

 using namespace std;

 Node::Node(Student* newStudent) {
   theStudent = newStudent;
   next = NULL;
 }

 Node::~Node() {
   delete(theStudent);
   next = NULL;
 }
 void Node::setNext(Node* nextNode) {


   next = nextNode;
 }


 Node* Node::getNext() {
   return next;
 }

 void Node::setPrevious(Node* previousNode) {
   previous = previousNode;
 } 

 Node* Node::getPrevious() {
   return previous;
 }

 Student* Node::getStudent() {
   return theStudent;
 }




