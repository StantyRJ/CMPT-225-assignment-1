/*
 * MyADT.cpp
 * 
 * Class Description: A linear data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - This is a value-oriented data collection: the elements are kept in 
 *                     ascending sort order of search key. 
 *                   - Its data structure is not expandable, i.e., resizable. 
 *
 * Author: AL
 * Last modified on: Sept. 2023
 */


#include <iostream>
#include <cctype>
#include "MyADT.h"  // Header file
#include "Profile.h"

using std::cout;
using std::endl;


    
// Default constructor.
MyADT::MyADT() {
    for(int alph = 0; alph < MAX_ALPHA; alph++)
    {
      elements[alph] = new Profile[MAX_ELEMENTS];
      elementCount[alph] = 0;
    }
}  // end default constructor


// Copy constructor - Covered in Lab 3
MyADT::MyADT(const MyADT& rhs) {
    for(int alph = 0; alph < MAX_ALPHA; alph++)
    {
      elementCount[alph] = rhs.elementCount[alph];
      // Deep copy each element (?)
      elements[alph] = new Profile[MAX_ELEMENTS];
      for(int i = 0; i < elementCount[alph]; i++)
      {
         elements[alph][i] = rhs.elements[alph][i];
      }
    }
}  // end copy constructor


// Destructor
// Description: Destruct this object, releasing heap-allocated memory.
MyADT::~MyADT() {
   for(int alph = 0; alph < MAX_ALPHA; alph++)
   {
      delete [] elements[alph];
   }
} // end destructor

// Description: Returns the total element count of elements currently stored in MyADT.
unsigned int MyADT::getElementCount() const {
   unsigned int total = 0;
   for(int i = 0; i < MAX_ALPHA; i++)
      total += elementCount[i];
   return total;
}  // end getElementCount


// Description: Inserts an element.
// Precondition: newElement must not already be in data collection.  
// Postcondition: newElement inserted and the appropriate elementCount has been incremented.
//                Returns "true" when the insertion is successfull,
//                otherwise "false".
bool MyADT::insert(const Profile& newElement) {
   int pos = (int) newElement.getUserName()[0];
   if(pos > 90)
      pos -= 97;
   else
      pos -= 65;

   if(elementCount[pos] >= MAX_ELEMENTS)
   {
      return false;
   }

   for(int i = 0; i < elementCount[pos]; i++)
   {
      if(elements[pos][i] == newElement)
      {
         return false;
      }

      if(&elements[pos][i] == nullptr)
      {
         elements[pos][elementCount[pos]] = newElement;  
         elementCount[pos] ++;
         return true;       
      }
   }
   elements[pos][elementCount[pos]] = newElement;
   elementCount[pos] ++;
   return true;
}  // end insert


// Description: Search for target element. 
//              Returns a pointer to the element if found,
//              otherwise, returns nullptr.
Profile* MyADT::search(const Profile& target) {
   int pos = (int) target.getUserName()[0];
   if(pos > 90)
      pos -= 97;
   else
      pos -= 65;
      
   for(int i = 0; i < elementCount[pos]; i++)
   {
      if(elements[pos][i] == target)
         return &elements[pos][i];
   }   

   return nullptr;

}  // end of search

// Description: Remove an element. 
// Postcondition: toBeRemoved is removed and the appropriate elementCount has been decremented.
//                Returns "true" when the removal is successfull,
//                otherwise "false".
bool MyADT::remove(const Profile& toBeRemoved) {
   int pos = (int) toBeRemoved.getUserName()[0];
   if(pos > 90)
      pos -= 97;
   else
      pos -= 65;
      
   for(int i = 0; i < elementCount[pos]; i++)
   {
      if(elements[pos][i] == toBeRemoved)
      {
         for(int next = i; next < elementCount[pos]-1; next++)
         {
            elements[pos][next] = elements[pos][next+1];
         }
         elementCount[pos] --;
         return true;
      }
   }   

   return false;
}  // end remove


// Description: Remove all elements.
// Postcondition: MyADT goes back to its initialization state.
void MyADT::removeAll() {
   for(int alph = 0; alph < MAX_ALPHA; alph++)
   {
      elementCount[alph] = 0;
   }
}  // end removeAll


// Description: Prints all elements stored in MyADT by ascending order of search key.
// ***For Testing Purposes - Conceptualy, it is not part of this class.***
void MyADT::print() {
   for(int alph = 0; alph < MAX_ALPHA; alph++)
   {
      for(int i = 0; i < elementCount[alph]; i++)
      {
         Profile cur = elements[alph][i];
         cout << cur.getUserName() << ", " << cur.getEmail() << ", " << cur.getEmail() << ", " << cur.getBirthday() << endl;
      }
   }

} // end of print 

//  End of implementation file
