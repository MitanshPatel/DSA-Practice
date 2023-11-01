// Given K sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list.

// Example 1:
// Input:
// K = 4
// value = {{1,2,3},{4 5},{5 6},{7,8}}
// Output: 1 2 3 4 5 5 6 7 8
// Explanation:
// The test case has 4 sorted linked 
// list of size 3, 2, 2, 2
// 1st    list     1 -> 2-> 3
// 2nd   list      4->5
// 3rd    list      5->6
// 4th    list      7->8
// The merged list will be
// 1->2->3->4->5->5->6->7->8.

#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

struct compare {
    bool operator() (Node*a , Node* b){
        return a->data > b->data;
    }
};
//Function to merge K sorted linked list.
Node * mergeKLists(Node *arr[], int K)
{
    // Your code here
    priority_queue<Node* ,vector<Node*>, compare> minHeap;
    for( int i=0;i<K;i++){
        if(arr[i]!=NULL){
            minHeap.push(arr[i]);
        }    
    }
    Node* head = NULL;
    Node *tail = NULL;
    while(minHeap.size()>0){
        Node* top = minHeap.top();
        minHeap.pop();
        
        if(top->next != NULL){
            minHeap.push(top->next);
        }
        if(head == NULL){
            head = top;
            tail = top;
        }
        else{
            tail->next = top;
            tail = top;
        }
        
    }
    return head;
}