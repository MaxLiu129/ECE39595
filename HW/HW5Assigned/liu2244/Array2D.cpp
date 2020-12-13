#include <iostream>
#include <cstdlib>
#include "Array2D.H"

// The character parameter exists to give this a different signature than any of 
// the public constructors.
Array2D::Array2D(int numR, int numC, char differentiator) : numRows(numR), numCols(numC) {

   ary = (int **)malloc(numRows * sizeof(int *)); 
   for (int i = 0; i < numRows; i++) {
      ary[i] = (int *)malloc(numCols * sizeof(int)); 
      for (int j = 0; j < numCols; j++) {
            ary[i][j] = -1;
      }
   }
}

Array2D::Array2D(int numR, int numC) : Array2D(numR, numC, 'c') { 
   for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numCols; j++) {
         ary[i][j] = i;
      }
   }
}

Array2D::Array2D(int numR, int numC, int val) : Array2D(numR, numC, 'c') { 
   for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numCols; j++) {
         ary[i][j] = val;
      }
   }
}

int& Array2D::operator( )(int row, int col) {
   return ary[row][col];
}
      
int Array2D::operator( )(int row, int col) const {
   return ary[row][col];
}

bool Array2D::sameSize(const Array2D& other) const {
   return (numRows == other.getNumRows( ) && numCols == other.getNumCols( ));
}

void Array2D::deleteAry(int** ary) {
   for (int i = 0; i < numRows; i++) {
      delete [ ] ary[i];
   }
   delete [ ] ary;
}

// new funcs
Array2D::Array2D(Array2D& other){
   int row = other.getNumRows();
   int col = other.getNumCols();
   ary = (int **)malloc(numRows * sizeof(int *)); 


   return ary;
}

void ~Array2D(int** ary){  
   
   for (int i = 0; i < numRows; i++) {
      delete [ ] ary[i];
   }
   delete [ ] ary;
}

int getNumRows( ){

}
bool operator==(Array2D& ary1, Array2D& ary2){
   return true; //change
}
// int getNumCols( ){

// }

/*
   
   Array2D& operator=(const Array2D& ary);
   bool operator==();
   Array2D& operator*();
   std::ostream operator<<();
   
*/
