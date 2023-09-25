/*
 * FriendsBook.cpp - Assignment 1
 * 
 * Class Description: Social network application (partial implementation).
 *
 * In this version, we use our MyADT.
 *
 * ***You cannot remove/change the code provided in this file.***
 *
 * Author: AL
 * Modified on: Sept. 14, 2023
 */

#include <iostream>
#include <string>
#include <cctype>
#include "Profile.h"
#include "MyADT.h"

using std::cout;
using std::ws;
using std::cin;
using std::endl;


void join(MyADT & theMembers) {
   string username, name, email, birthday;
   cout << "Enter your username: ";
   cin >> username;
   cout << "Enter your name: ";
   cin >> name;
   cout << "Enter your email: ";
   cin >> email;
   cout << "Enter your birthday (format: MM/DD/YYYY): ";
   cin >> birthday;
   Profile *newProfile = new Profile(username,name,email,birthday);
   bool result = theMembers.insert(*newProfile);
   if(result)
      cout << "Profile successfully created" << endl;
   else
   {
      cout << "Try again with a different username" << endl;
      delete newProfile;
   }
}

void leave(MyADT & theMembers) {
   string username, name, email, birthday;
   cout << "Enter your username: ";
   cin >> username;
   cout << "Enter your name: ";
   cin >> name;
   cout << "Enter your email: ";
   cin >> email;
   cout << "Enter your birthday (format: MM/DD/YYYY): ";
   cin >> birthday;
   Profile *newProfile = new Profile(username,name,email,birthday);
   theMembers.remove(*newProfile);
}

void search(MyADT & theMembers) {

}

void modify(MyADT & theMembers) {

   /* Put your code here */

}

void print(MyADT & theMembers) {
   theMembers.print();
}

int main() {

    // Variables declaration
    MyADT members = MyADT();  // Object MyADT on the stack, its arrays on the heap
    bool done = false;
    char input = 0;
        
    // Keep going until the user exits
    while (not done) {
        // Print menu to stdout
        cout << "\n----Welcome to FriendsBook!" << endl << endl;
        cout << endl << "Enter ..." << endl;
        cout << "j -> to join FriendsBook by creating a profile." << endl;
        cout << "l -> to leave FriendsBook." << endl;
        cout << "s -> to search for a friend on FriendsBook." << endl;
        cout << "m -> to modify your profile on FriendsBook." << endl;
        cout << "p -> to print all members on FriendsBook." << endl;
        cout << "x -> to exit FriendsBook." << endl << endl;


        cout << "Your choice: ";
        cin >> input;
        cout << endl;
        input = tolower(input);
        switch(input) {
            case 'j': join(members); break;
            case 'l': leave(members); break;
            case 's': search(members); break;
            case 'm': modify(members); break;
            case 'p': print(members); break;
            case 'x': cout << "\n----Bye!\n" << endl; 
                      done = true; break;
            default: cout << "Not sure what you mean! Please, try again!" << endl;
        }
    }

   delete &members;
   return 0;
}
