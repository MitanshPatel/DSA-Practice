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

//INSERTION
Node* insertionSort(struct Node* head)
{
    //code here
    Node *dummy=new Node(1000);
    while(head){
        Node *nxt=head->next;
        Node *temp=dummy;
        
        while(temp->next && temp->next->data < head->data){
            temp=temp->next;
        }
        head->next=temp->next;
        temp->next=head;
        head=nxt;
    }
    return dummy->next;
}

//MERGE
Node *Mid(Node *head){
    Node *slow=head;
    Node *fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
    
Node *mergeIt(Node *p1, Node *p2){
    if(p1==NULL) return p2;
    if(p2==NULL) return p1;
    Node *ans=new Node(0);
    Node *curr=ans;
    
    while(p1!=NULL && p2!=NULL){
        if(p1->data < p2->data){
            curr->next=p1;
            p1=p1->next;
            curr=curr->next;
        }else{
            curr->next=p2;
            p2=p2->next;
            curr=curr->next;
        }
    }
    
    if(p1!=NULL) curr->next=p1;
    if(p2!=NULL) curr->next=p2;
    return ans->next;
}
//Function to sort the given linked list using Merge Sort.
Node* mergeSort(Node* head) {
    // your code here
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *mid=Mid(head);
    Node *newHead=mid->next;
    mid->next=NULL;
    Node *left=mergeSort(head);
    Node *right=mergeSort(newHead);
    return mergeIt(left,right);
    
}