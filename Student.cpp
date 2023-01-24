
 #include <iostream>
 #include <cstring>
 #include "Student.h"
 using namespace std;

 void Student::setFirstName(const char* firstNameTemp){
   strcpy(firstName, firstNameTemp);
 }

