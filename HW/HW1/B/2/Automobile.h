#ifndef AUTOMOBILE_H_
#define AUTOMOBILE_H_

#include <string>

class Automobile {
   private:
      int id;
      float mileage;
      int month;
      int date;
      int year;

   public:
      int getID();
      int getmm();
      int getdd();
      int getyy();
      float getMileage();
      Automobile(int id_input, float mileage_input, int mm_input, int dd_input, int yy_input);
      std::string printthings( );
};
#endif /* ADDRESS_H_ */
