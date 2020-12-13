#include <iostream>
#include "Person.h"

Person::Person(long _SSN, long _phone)  /* need to add initializer and constructor calls here */ {
   SSN = _SSN;
   phone = _phone;
   std::cout << "Person" << std::endl;
}

long Person::getSSN( ) {
   return SSN;
}

void Person::setSSN(long _SSN) {
   SSN = _SSN;
}

long Person::getPhone( ) {
   return phone;
}

void Person::setPhone(long _phone) {
   phone = _phone;
}
