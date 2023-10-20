// Design a data structure that works like a LRU Cache. Here cap denotes the capacity of the cache and Q denotes the number of queries. Query can be of two types:

// SET x y: sets the value of the key x with value y
// GET x: gets the key of x if present else returns -1.

// Input:
// cap = 2
// Q = 8
// Queries = SET 1 2 SET 2 3 SET 1 5
// SET 4 5 SET 6 7 GET 4 SET 1 2 GET 3
// Output: 5 -1
// Explanation: 
// Cache Size = 2
// SET 1 2 : 1 -> 2

// SET 2 3 : 1 -> 2, 2 -> 3 (the most recently 
// used one is kept at the rightmost position) 

// SET 1 5 : 2 -> 3, 1 -> 5

// SET 4 5 : 1 -> 5, 4 -> 5 (Cache size is 2, hence 
// we delete the least recently used key-value pair)

// SET 6 7 : 4 -> 5, 6 -> 7 

// GET 4 : Prints 5 (The cache now looks like
// 6 -> 7, 4->5)

// SET 1 2 : 4 -> 5, 1 -> 2 
// (Cache size is 2, hence we delete the least 
// recently used key-value pair)

// GET 3 : No key value pair having 
// key = 3. Hence, -1 is printed.

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int key;
    int val;
    Node *prev;
    Node *next;
    Node(int k,int value)
    {
        key = k;
        val = value;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache
{
    private:
    Node* head = new Node(0,0);
    Node* tail = new Node(0,0); 
    unordered_map<int,Node*> mp;
    int capacity;
    public:
    
    
    void addNode(int key, int val)
    {
        Node *createNode = new Node(key,val);
        Node *temp = head->next;
        head->next = createNode;
        temp->prev = createNode;
        createNode->next = temp;
        createNode->prev = head;
    }
    
    
    void deleteNode(Node* &node)
    {
        Node *pre = node->prev;
        Node *post = node->next;
        pre->next = post;
        post->prev = pre;
        delete(node);
    }
    
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        capacity = cap;
        head->next = tail;
        tail->prev = head;
    }
    
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        if(mp.find(key) != mp.end())
        {
            Node *foundNode = mp[key];
            int ans = foundNode->val;
            deleteNode(foundNode);
            addNode(key,ans);
            mp.erase(key);
            mp[key] = head->next;
            return ans;
        }
        return -1;
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        
        if(mp.find(key) != mp.end())
        {
            Node *toDelete = mp[key];
            mp.erase(key);
            deleteNode(toDelete);
        }
        else if(mp.size() == capacity)
        {
            Node *toDelete = tail->prev;
            mp.erase(toDelete->key);
            deleteNode(toDelete);
        }
        addNode(key,value);
        mp[key] = head->next;
    } 
};