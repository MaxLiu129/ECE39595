#include <iostream>
#include <string>

template <class TPL> class Node { 
   TPL data;
   Node* left = nullptr;
   Node* right = nullptr;
public:
   Node( );
   Node(TPL val);
   void print( ) const;
   Node* insertNode(TPL n);
};


template <class TPL> Node<TPL>::Node( ) { }

template <class TPL> Node<TPL>::Node(TPL val) {
   data = val;
}

template <class TPL> void Node<TPL>::print( ) const {
   if (this->left != nullptr) {
      this->left->print( );
   }
   std::cout << data << " ";
   if (this->right != nullptr) {
      this->right->print( );
   }
}

template <class TPL> Node<TPL>* Node<TPL>::insertNode(TPL n) {
   if (this->data == n) return this;
   if (n < this->data) {
      if (left != nullptr) return left->insertNode(n); 
      else {
         left = new Node<TPL>(n);
         return left;
      }
   }
   if (n > this->data) {
      if (right != nullptr) return right->insertNode(n); 
      else {
         right = new Node<TPL>(n);
         return left;
      }
   }
   return nullptr;
}
