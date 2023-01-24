/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
if(in == nullptr) return;//base condition stop the recursion
  int value = in->value;//read value from the 1st node in the in list
  Node* next = in->next; //read the pointer to next element
  delete in;  // delete the first node 
  in = next;  // to fix the list we set the 1st node to the previouslly saved
  //pointer to the next element. we set the in pointer to next node
  Node* n = new Node(value, nullptr); //create a node n that not belong any list, 
  //set the value we delete to n.
  
  if (value % 2 == 0) 
  {
    // even
    //case 1: evens list not created yet
    if (evens == nullptr) 
    {
      evens = n; //create the list (1st element is n)
      split(in, odds, evens); //
    } 
    else //case 2 evens' list is not empty
    {
      evens->next = n; //link the last element and n.n will the part of the list
      split(in, odds, evens->next);
    }
  } 
   else 
  {
    // odd: list is empty
    if (odds == nullptr) 
    {
      odds = n;
      split(in, odds, evens);
    } 
    else //odd: list is not empty
    {
      odds->next = n;
      split(in, odds->next, evens); 
    }
  }
}

/* If you needed a helper function, write it here */
