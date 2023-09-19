/* C++ program to reverse a doubly linked list */

#include <bits/stdc++.h>
using namespace std;

/* Node of the doubly linked list */
class Node {
public:
	int data;
	Node* next;
	Node* prev;
};

//REVERSE
Node* reverse(Node* head)
{
	Node *ptr1=head;
    Node *ptr2=ptr1->next;
    if(ptr2==NULL) return head;
    
    ptr1->next=NULL;
    ptr1->prev=ptr2;
    
    while(ptr2!=NULL){
        ptr2->prev=ptr2->next;
        ptr2->next=ptr1;
        ptr1=ptr2;
        ptr2=ptr2->prev;
    }
    head=ptr1;
    return head;
}

/* UTILITY FUNCTIONS */
/* Function to insert a node at the
beginning of the Doubly Linked List */
void push(Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = new Node();

	/* put in the data */
	new_node->data = new_data;

	/* since we are adding at the beginning,
	prev is always NULL */
	new_node->prev = NULL;

	/* link the old list of the new node */
	new_node->next = (*head_ref);

	/* change prev of head node to new node */
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print nodes in a given doubly linked list
This function is same as printList() of singly linked list
*/
void printList(Node* node)
{
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
}

// Driver's code
int main()
{
	/* Start with the empty list */
	Node* head = NULL;

	/* Let us create a sorted linked list to test the
	functions Created linked list will be 10->8->4->2 */
	push(&head, 2);
	push(&head, 4);
	push(&head, 8);
	push(&head, 10);

	cout << "Original Linked list" << endl;
	printList(head);

	// Function call
	head=reverse(head);

	cout << "\nReversed Linked list" << endl;
	printList(head);

	return 0;
}

// This code is contributed by rathbhupendra
