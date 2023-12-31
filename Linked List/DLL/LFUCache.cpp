// Design and implement a data structure for a Least Frequently Used (LFU) cache.

// Implement the given LFUCache Class with the following description.

// LFUCache(int capacity): This Initializes the object with the capacity of the data structure.

// int get(int key): Returns the value of the given key if it exists or else returns -1.

// void put(int key, int value): If the key is already present, then update its value and if the key is not present, then it should be inserted.
// If the data  structure has reached its maximum capacity, then the least frequently used (LFU) key should be invalidated and removed.
// If during removal, more than one key has same frequency, then the Least Recently Used (LRU) key amongst them should be removed.

// Example:

// Input: 
// Capacity: 3
// put(5,7)put(4,6)put(3,5)put(2,4)put(1,3)
// get(1)get(2)get(3)get(4)get(5)

// Output: 
// 3
// 4
// 5
// -1
// -1
// Explanation: 
// When put(2,4) is executed, (5,7) gets invalidated.
// Similarly when put(1,3) is executed, (4,6) gets invalidated.
// Therefore only the values for key 1,2,3 are present in the cache after all the put operations.

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int key,value,count;
    Node*next;
    Node*prev;
    Node(int _key, int _value){
        key= _key;
        value= _value;
        count= 1;
        
    }
};


struct List{
   int size;
   Node* head;
   Node* tail;
   
   List(){
       
       head= new Node(0,0);
       tail= new Node(0,0);
       
       head->next= tail;
       tail->prev= head;
       size= 0;
       
   }
   
   void addFront(Node* node){
       Node* temp= head->next;
       node->next= temp;
       node->prev= head;
       head->next= node;
       temp->prev= node;
       size++;
   }
   
   void removeNode(Node* delnode){
       Node* delprev= delnode->prev;
       Node* delnext= delnode->next;
       
       delprev->next= delnext;
       delnext->prev= delprev;
       size--;
       
   }
   
};
       


class LFUCache {
    
    map<int, Node*> keyNode;
    map<int, List*> freqListMap;
    int maxSizeCache;
    int minFreq;
    int curSize;
    
    public:
    LFUCache(int capacity) {
        maxSizeCache= capacity;
        minFreq= 0;
        curSize= 0;
    }
    
    void updateFreqListMap(Node* node){
        keyNode.erase(node->key);
        freqListMap[node->count]->removeNode(node);
        if(node->count==minFreq && freqListMap[node->count]->size==0){
            minFreq++;
        }
        
        List* nextHigherFreqList= new List();
        
        if(freqListMap.find(node->count+1)!= freqListMap.end()){
            nextHigherFreqList= freqListMap[node->count+1];
            
        }
        
        node->count+= 1;
        nextHigherFreqList->addFront(node);
        freqListMap[node->count]= nextHigherFreqList;
        keyNode[node->key]= node;
    
    }
    
    int get(int key) {
        if(keyNode.find(key)!=keyNode.end()){
            Node* node= keyNode[key];
            int val= node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxSizeCache==0){
            return;
        }
        if(keyNode.find(key)!= keyNode.end()){
            Node* node= keyNode[key];
            node->value= value;
            updateFreqListMap(node);
        }
        
        else{
            if(curSize== maxSizeCache){
                List* list= freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->removeNode(list->tail->prev);
                curSize--;
            }
            
            curSize++;
            minFreq= 1;
            
            List* listFreq= new List();
            if(freqListMap.find(minFreq)!= freqListMap.end()){
                listFreq= freqListMap[minFreq];
            }
            
            Node* node= new Node(key, value);
            listFreq->addFront(node);
            keyNode[key]= node;
            freqListMap[minFreq]= listFreq;
        }
    }
};