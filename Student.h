
 #ifndef STUDENT_H
 #define STUDENT_H

 #include <iostream>
 #include <cstring>
 using namespace std;

 class Student{

  public:
   void setFirstName(const char* newFirst);
   void	setLastName(const char* newLast);
   void setID(int newID);
   void	setGPA(float newGPA);
   char*getFirstName();
   char*getLastName();
   int* getID();
   float* getGPA();

  private:
   char firstName[100];
   char lastName[100];
   int id;
   float gpa;
 };

 #endif
