// Given a singly linked list of size N. The task is to left-shift the linked list by k nodes, 
//where k is a given positive integer smaller than or equal to length of the linked list.

// Example 1:

// Input:
// N = 5
// value[] = {2, 4, 7, 8, 9}
// k = 3
// Output: 8 9 2 4 7
// Explanation:
// Rotate 1: 4 -> 7 -> 8 -> 9 -> 2
// Rotate 2: 7 -> 8 -> 9 -> 2 -> 4
// Rotate 3: 8 -> 9 -> 2 -> 4 -> 7

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

Node *rotate(Node *head, int k)
{
    // Your code here
    if (head == NULL || head->next == NULL)
        return head;
    Node *prev = head;
    Node *curr = head;

    Node *tail = head;
    while (tail->next)
        tail = tail->next;
    for (int i = 0; i < k; i++)
    {
        curr = prev->next;
        tail->next = prev;
        prev->next = NULL;
        tail = prev;
        prev = curr;
    }
    return curr;
}