#include "Person.h"
#include "Student.h"
#include "Faculty.h"
#include <iostream>

int main() {
   Faculty* f = new Faculty(2,2,2,"Dumbledore");
   Person* temp = static_cast<Person*> (f);
   Student* s = static_cast<Student*> (temp); 
   f->putSalary(1500.0); // Statement S0
   std::cout << "before putGPA(6,6) called" << std::endl;
   s->putGPA(6.6); // Statement S1
   std::cout << "before getGPA called " << std::endl;
   s->getGPA( ); // Statement S2
   std::cout << std::endl;

   Person* temp1 = new Student(3,3,3,"Irena"); // illegal!
   f = static_cast<Faculty*> (temp1);
   std::cout << "before putSalary called " << std::endl;
   f->putSalary(500.0); // Statement S3
   std::cout << "before getSalary called " << std::endl;
   f->getSalary( ); // Statement S4
   std::cout << std::endl;

   Person* temp2 = new Person(1,1,1,"Bob");
   s = static_cast<Student*> (temp2);
   std::cout << "before getGPA is called " << std::flush << std::endl;
   s->getGPA( ); // Statement S5
   std::cout << "finished" << std::flush << std::endl;
}
