/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"

#include <iostream>
using namespace std;


void print(Node *head);
Node* createLL()
{
    Node *head = new Node(0,nullptr);
    Node *temp = head;
    for(int i = 0;i<10;i++)
    {
        Node *n = new Node(0,nullptr);
        n->value = i+1;
        n->next = nullptr;
        temp->next = n;
        temp = temp->next;
    }
    return head;
}

void print(Node *head)//print forward
{
    Node* temp = head;
    if(temp == nullptr)
    return;
    else
    cout<<temp->value<<"     ";
    print(temp->next); 
}

void print2(Node *head)
{
    if(head == nullptr)
    return;
    print2(head->next); 
    cout<<head->value<<"     ";//print backward
}

void freeList(Node* head)//detele from last to first
{
    if(head == nullptr)return;
    freeList(head->next);
    delete head;//important delete after recursion
                //delete it before , we cannot accece next.   
}

void freeList2(Node* head)//delete element from 1st to the last
{
    if(head == nullptr)return;
    Node* next = head->next;//save the next pointer
     delete head;
    freeList2(next);
}

void test()
{
    Node* head = createLL();
    print(head);
    Node *evens = nullptr;
    Node *odds  = nullptr;
    
    split(head,odds,evens);
    cout<<endl<<"evens: "<<endl;
    print(evens);
    cout<<endl;
    cout<<"odds: "<<endl;
    print(odds);
    if(head != nullptr)
    cout<<" error head is expexted to nullptr "<<endl;
    freeList(evens);
    freeList(odds);
    cout<<endl;

    
    
}

int main()
{      
    test();

    return 0;
}