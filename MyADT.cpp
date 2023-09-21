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
    MyADT *newADT = new MyADT; 
    for(int alph = 0; alph < newADT->MAX_ALPHA; alph++)
    {
        for(int i = 0; i < newADT->MAX_ALPHA; i++)
        {
            elements[alph][i] = new Profile;
        }
    }
}  // end default constructor


// Copy constructor - Covered in Lab 3
MyADT::MyADT(const MyADT& rhs) {

    MyADT *newADT = new MyADT;
    for(int alph = 0; alph < newADT->MAX_ALPHA; alph++)
    {
        for(int i = 0; i < newADT->MAX_ALPHA; i++)
        {
            elements[alph][i] = 
        }
    }

}  // end copy constructor


// Destructor
// Description: Destruct this object, releasing heap-allocated memory.
MyADT::~MyADT() {

   /* Put your code here */

} // end destructor

// Description: Returns the total element count of elements currently stored in MyADT.
unsigned int MyADT::getElementCount() const {

   /* Put your code here */

}  // end getElementCount


// Description: Inserts an element.
// Precondition: newElement must not already be in data collection.  
// Postcondition: newElement inserted and the appropriate elementCount has been incremented.
//                Returns "true" when the insertion is successfull,
//                otherwise "false".
bool MyADT::insert(const Profile& newElement) {

   /* Put your code here */

}  // end insert


// Description: Search for target element. 
//              Returns a pointer to the element if found,
//              otherwise, returns nullptr.
Profile* MyADT::search(const Profile& target) {

   /* Put your code here */

}  // end of search

// Description: Remove an element. 
// Postcondition: toBeRemoved is removed and the appropriate elementCount has been decremented.
//                Returns "true" when the removal is successfull,
//                otherwise "false".
bool MyADT::remove(const Profile& toBeRemoved) {

   /* Put your code here */

}  // end remove


// Description: Remove all elements.
// Postcondition: MyADT goes back to its initialization state.
void MyADT::removeAll() {

   /* Put your code here */

}  // end removeAll


// Description: Prints all elements stored in MyADT by ascending order of search key.
// ***For Testing Purposes - Conceptualy, it is not part of this class.***
void MyADT::print() {

   /* Put your code here */

} // end of print 

//  End of implementation file
