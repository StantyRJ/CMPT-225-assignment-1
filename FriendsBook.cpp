/*
 * FriendsBook.cpp - Assignment 1
 * 
 * Class Description: Social network application (partial implementation).
 *
 * In this version, we use our MyADT.
 *
 * ***You cannot remove/change the code provided in this file.***
 *
 * Author: Ryan Hargrave
 * Student #: 301550214
 * Modified on: Sept. 14, 2023
 * Last modified on: Sept. 29 2023
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

//Description: asks the user for a username and returns a pointer 
//             to a new profile with that username
Profile *makeProfile()
{
   string username;
   cout << "Enter your username: ";
   cin >> username;
   return new Profile(username);
}

//Description: asks the user for username, name, email and birthday
//             then makes a new profile and inserts it into the ADT
//             then prints out if the insertion is successful or not
void join(MyADT & theMembers) {
   string username, name, email, birthday;
   cout << "Enter your username (only letters allowed): ";
   cin >> username;
   cout << "Enter your name: ";
   cin >> name;
   cout << "Enter your email: ";
   cin >> email;
   cout << "Enter your birthday: ";
   cin >> birthday;
   Profile *newProfile = new Profile(username,name,email,birthday);

   if(theMembers)
      bool result = theMembers.insert(*newProfile);

   if(result)
      cout << "Profile successfully created" << endl;
   else
   {
      cout << "Try again with a different username. There may already be a user with that name." << endl;
   }
   delete newProfile;
}

//Description: asks the user for a username then 
//             removes that user from the adt if it is found;
void leave(MyADT & theMembers) {
   Profile *newProfile = makeProfile();
   bool removed = theMembers.remove(*newProfile);
   if(removed)
      cout << "Profile removed." << endl;
   else
      cout << "Profile not found." << endl;

   delete newProfile;
}

//Description: look for the username the user enters and return if they are a member
void search(MyADT & theMembers) {
   Profile *newProfile = makeProfile();
   Profile *profileFound = theMembers.search(*newProfile);
   if(profileFound)
      cout << "Your friend was found!";
   else
      cout << "Your friend was not found.";

   delete newProfile;
}

//Description: search for the username inputed and allow the user
//             to change the name email and birthday of that user
void modify(MyADT & theMembers) {
   string username, name, email, birthday;
   cout << "Enter the username of the account you want to edit: ";
   cin >> username;
   Profile *newProfile = new Profile(username);
   Profile *profileFound = theMembers.search(*newProfile);
   if(profileFound)
   {
      cout << "Enter your new name: ";
      cin >> name;
      cout << "Enter your new email: ";
      cin >> email;
      cout << "Enter your new birthday: ";
      cin >> birthday;
      profileFound->setName(name);
      profileFound->setEmail(email);
      profileFound->setBirthday(birthday);
      cout << "Your profile has been updated" << endl;
   }
   else
   {
      cout << "That profile was not found." << endl;
   }
   delete newProfile;
}

//Description: prints all the members of the ADT
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
   return 0;
}
