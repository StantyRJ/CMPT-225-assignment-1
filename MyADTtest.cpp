#include <iostream>
#include <string>
#include <cctype>
#include "Profile.h"
#include "MyADT.h"

using std::cout;
using std::endl;

int main()
{
    MyADT members = MyADT(); 

    Profile theMemberA[] = {Profile("Amy"),Profile("August"),Profile("Alex"),Profile("Arwin")};
    Profile theMemberD[] = {Profile("Donny"),Profile("diana"),Profile("dominique"),Profile("dick"),Profile("darwin")};
    Profile theMemberQ[] = {Profile("Qi"),Profile("Quest"),Profile("Quinn"),Profile("Quincey"),Profile("Quack")};

    for(int i = 0; i < 5; i++)
    {
        cout << "Members inserted." << endl;
        members.insert(theMemberA[i]);
        members.insert(theMemberD[i]);
        members.insert(theMemberQ[i]);
    }

    //check what happens if duplicates
    if(!members.insert(theMemberA[0])) {cout << "Duplicate caught!" << endl;};

    //check for too many items
    if(!members.insert(Profile("daria"))) {cout << "Too many items" << endl;};

    members.print();

    cout << endl << "new ADT created + members copied over" << endl;
    MyADT members2 = MyADT(members); 
    members2.insert(Profile("joe"));
    members2.print();

    cout << members2.getElementCount() << " Elements in ADT" << endl;

    cout << members2.search(Profile("joe")) << " item found"<<endl;
    cout << members2.search(Profile("molly")) << " item not found " << endl;

    members2.remove(Profile("joe"));
    cout << "Joe removed" << endl;
    members2.print();

    members2.removeAll();
    cout << "All elements removed" << endl;
    members2.print();

    for(int i = 0; i < 5; i++)
    {
        members2.insert(theMemberA[i]);
        members2.insert(theMemberD[i]);
        members2.insert(theMemberQ[i]);
    }

    members2.print();
    return 0;
}