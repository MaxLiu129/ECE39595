#ifndef ARRAY2D_H_
#define ARRAY2D_H_
#include <iostream>
class Array2D {

public:
   Array2D(int numR, int numC); 
   Array2D(int numR, int numC, int val); 

   virtual int& operator( )(int row, int col);
   virtual int operator( )(int row, int col) const;

   Array2D(Array2D& other);
   ~Array2D();
   Array2D& operator=(const Array2D& ary);
   bool operator==(Array2D& ary1, Array2D& ary2);
   Array2D& operator*( );
   std::ostream operator<<( );
   int getNumRows( );
   int getNumCols( );

private:
   Array2D(int numR, int numC, char differentiator);
   void deleteAry(int** ary);
   bool sameSize(const Array2D& other) const;
};
#endif /* ARRAY2D_H_ */
