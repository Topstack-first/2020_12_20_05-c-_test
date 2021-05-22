// CS 115 Final Exam -- U of R Fall 2020
// Solution for Question 3
// Instructor: Gurmail Singh
// Student Name:
// Student ID:

#include<iostream>

using namespace std;

struct House
{
    string firstName;
    int houseNumber;

};

struct Node
{
    House datum;
    Node* pNext;

};


class SortedLinkedList
{

private:
    Node* pHead;

public:

    SortedLinkedList()
    {
        pHead = nullptr;
    }

    SortedLinkedList(Node* link)
    {
        pHead = link;
    }

    bool isEmpty()
    {
        return (pHead == nullptr);
    }

    /*You can write the following function here or use scope resolution (::)
      to write it outside the class to create a singly linked list.

      You need to prompt the user to provide the number of node
      that the user want to have in the linked list,
      and get the inputs from use for each node.
      */

    void CreateList();

     /*This function returns the address of a node from the linked list whose first name is
      smaller than first name of the node that we want to either add to or remove from the
      linked list.*/

    Node* searchLinkedList(Node* pHead, House house)
    {

        Node* pPrevious  = nullptr;
        Node* pCurrent = pHead;

        while (pCurrent != nullptr&& pCurrent->datum.firstName<house.firstName)
        {
            pPrevious = pCurrent;
            pCurrent =pCurrent->pNext;
        }
        return pPrevious;
    }

    //You can use the above function to add and remove nodes from the linked list.

    //function to insert
    void insert(Node * node)
    {
        Node* curNode = this->pHead;
        Node* loopNode = this->pHead;

        //find position of node
        while (loopNode != nullptr)
        {
            curNode = loopNode;
            loopNode = loopNode->pNext;
        }

        //insert node to correct position
        if (curNode != nullptr)
        {
            curNode->pNext = node;
        }
    }

    //function to remove node
    void remove(Node * node)
    {
        if (node == nullptr)
            return;
        //find prev node
        Node* prevNode = searchLinkedList(pHead, node->datum);
        if (prevNode != nullptr)
        {
            //delete node
            prevNode->pNext = node->pNext;
            delete node;
        }
        else {
            //delete head node
            Node* temp = pHead;
            pHead = pHead->pNext;
            delete temp;
        }
        
    }
    //function to print
    void print()
    {
        Node* node = pHead;
        while (node != nullptr)
        {
            cout << node->datum.firstName << "," << node->datum.houseNumber<<endl;
            node = node->pNext;
        }
    }

};


int main()
{
    
    //declare elements of house
    House house1,house2,house3;
    house1.firstName = "Alice";
    house1.houseNumber = 1;

    house2.firstName = "Bob";
    house2.houseNumber = 2;

    house3.firstName = "Caren";
    house3.houseNumber = 3;

    //create new node and set data
    Node* node1 = new Node();
    node1->datum = house1;

    //create new node and set data
    Node* node2 = new Node();
    node2->datum = house2;

    //create new node and set data
    Node* node3 = new Node();
    node3->datum = house3;

    //set next element
    node1->pNext = node2;
    node2->pNext = node3;
    
    //declare linked list with first node
    SortedLinkedList linkedList(node1);

    //declare 4th element
    House house4;
    house4.firstName = "Dary1";
    house4.houseNumber = 4;

    //create new 4th node
    Node* node4 = new Node();
    node4->datum = house4;

    //insert 4th node to linked list
    linkedList.insert(node4);

    //delete nodes including 'e' in firstName
    Node* curNode = node1;
    while (curNode != nullptr)
    {
        Node* temp = curNode;
        curNode = curNode->pNext;
        string firstName = temp->datum.firstName;
        for (int i = 0; i < firstName.length(); i++)
            if (firstName[i] == 'e') {
                linkedList.remove(temp);
                break;
            }
                
    }

    //print all elements
    linkedList.print();

    return 0;
}
