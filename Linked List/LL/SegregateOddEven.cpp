// Given a link list of size N, modify the list such that all the even numbers appear before all the odd numbers in the modified list.
// The order of appearance of numbers within each segregation should be same as that in the original list.

// NOTE: Don't create a new linked list, instead rearrange the provided one.

// Example 1:

// Input:
// N = 7
// Link List:
// 17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6 -> NULL

// Output: 8 2 4 6 17 15 9

// Explaination: 8,2,4,6 are the even numbers
// so they appear first and 17,15,9 are odd
// numbers that appear later.
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

Node *divide(int N, Node *head){
    Node *evenHead = NULL, *evenTail = NULL, *oddHead = NULL, *oddTail = NULL;
    Node *curr = head;

    while (curr != NULL){
        int x = curr->data;

        if (x % 2 == 0){    //if even data came
            if (evenHead == NULL){   //if its 1st even, initialize the even head
                evenHead = curr;
                evenTail = curr;
            }
            else{   //attach even to end of even LL
                evenTail->next = curr;
                evenTail = curr;
            }
        } 
        else{   //if odd data detected
            if (oddHead == NULL){   //if its 1st odd
                oddHead = curr;
                oddTail = curr;
            }
            else{     //attach odd to end of odd LL
                oddTail->next = curr;
                oddTail = curr;
            }
        }
        curr = curr->next;
    }

    if (oddHead == NULL || evenHead == NULL)return head;    //if all elements in LL are even/odd
    evenTail->next = oddHead;  //attach even->odd
    oddTail->next = NULL;    //end the odd LL
    return evenHead;
}