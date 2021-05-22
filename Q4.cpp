// CS 115 Final Exam -- U of R Fall 2020
// Solution for Question 4
// Instructor: Gurmail Singh
// Student Name:
// Student ID:

#include<iostream>

//include header of stack
#include <stack>

using namespace std;

struct House
{
    string firstName;
    int houseNumber;

};


int main()
{
    //declare stack
    stack<House> myStack;

    //define elements
    House house1, house2, house3, house4;
    house1.firstName = "Paul";
    house1.houseNumber = 19;

    house2.firstName = "Johm";
    house2.houseNumber = 22;

    house3.firstName = "Patel";
    house3.houseNumber = 18;

    house4.firstName = "Abdul";
    house4.houseNumber = 29;

    //push elements
    myStack.push(house1);
    myStack.push(house2);
    myStack.push(house3);
    myStack.push(house4);

    //pop the last element
    myStack.pop();

    //print size of stack
    cout << "size=" << myStack.size()<<endl;

    //print all stack
    int size = myStack.size();
    for (int i = 0; i < size; i++)
    {
        House house = myStack.top();
        myStack.pop();
        cout << "firstName = " << house.firstName << "," << "houseNumber = " << house.houseNumber << endl;
    }
        

    return 0;
}
