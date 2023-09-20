// Iterative C++ program to reverse a linked list
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node* next;
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

struct LinkedList {
	Node* head;
	LinkedList() { head = NULL; }

	/* ITERATIVE*/
	Node * reverse()
	{
		// Initialize current, previous and next pointers
		if(head->next==NULL) return head;
        Node *p1=NULL;  //prev
        Node *p2=head;  //curr
        Node *p3=head->next;  //next
        while(p3!=NULL){
            //reverse the arrow
            p2->next=p1;
            //shift all ptr 1 node ahead
            p1=p2;
            p2=p3;
            p3=p3->next;
        }
        p2->next=p1;
        return p2;
	}
    //RECURSIVE
    Node* reverse(Node* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
 
        /* reverse the newHead list and put
          the first element at the end */
        Node* newHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
 
        /* fix the head pointer */
        return newHead;
    }

	/* Function to print linked list */
	void print(){
		struct Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	void push(int data)
	{
		Node* temp = new Node(data);
		temp->next = head;
		head = temp;
	}
};

/* Driver code*/
int main()
{
	/* Start with the empty list */
	LinkedList ll;
	ll.push(20);
	ll.push(4);
	ll.push(15);
	ll.push(85);

	cout << "Given linked list\n";
	ll.print();

	ll.reverse();

	cout << "\nReversed linked list \n";
	ll.print();
	return 0;
}
