
 #include <iostream>
 #include <cstring>
 #include "Student.h"
 using namespace std;

 void Student::setFirstName(const char* firstNameTemp){//sets first name of a student
   strcpy(firstName, firstNameTemp);
 }

 void Student::setLastName(const char* lastNameTemp){//sets last name of a student
   strcpy(lastName, lastNameTemp);
 }

 void Student::setID(int stuIDTemp){//sets id of a student
   id = stuIDTemp;
 }

 void Student::setGPA(float gpaTemp){//sets gpa of a student
   gpa = gpaTemp;
 }

 char* Student::getFirstName(){//returns first name of a student
   return firstName;
 }

 char* Student::getLastName(){//returns last name of a student
   return lastName;
 }

 int* Student::getID(){//returns id of a student
   return &id;
 }

 float* Student::getGPA(){//returns gpa of a student
   return &gpa;
 }
