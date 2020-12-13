#ifndef TA_H_
#define TA_H_
#include "Teacher.h"
#include "Student.h"

class TA : public Teacher, public Student {
public:
   TA(long _SSN, long _phone, double _contactHours, int _coursesTaught, 
      double credits, int coursesTaken);
};
#endif /* TA_H_ */
