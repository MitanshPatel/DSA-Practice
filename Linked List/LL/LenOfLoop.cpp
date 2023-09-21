//checks whether a given Linked List contains a loop or not and if the loop is present then return the count of nodes in a loop or else return 0.

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


//Function to find the length of a loop in the linked list.
int countNodesinLoop(struct Node *head){
    int cnt=0;
    Node *fast=head;
    Node *slow=head;
    
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        
        if(slow==fast){  //once the fast and slow meet, loop is present
            slow=slow->next;  //move slow to next node
            cnt=1;  //increase count
            while(slow!=fast){   //move slow around the loop until fast and slow meet again
                slow=slow->next;
                cnt++;  //increment count every time slow moves one node ahead
            }
            return cnt;
        }
    }
    return 0;
}