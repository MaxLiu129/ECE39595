#ifndef AUTOMOBILE_H_
#define AUTOMOBILE_H_

#include <string>

class Automobile {
   private:
      int id;
      float mileage;
      std::string maintainDate;

   public:
      int getID();
      float getMileage();
      std::string getDate();
      Automobile(int, float, int, int, int);
};
#endif /* ADDRESS_H_ */
