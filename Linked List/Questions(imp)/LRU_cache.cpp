#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Node{
public:
    int k;
    int val;
    Node *next;
    Node *prev;

    //initialize the node when an put is called a node is created
    Node(int key,int value){
        k=key;
        val=value;
        next=NULL;
        prev=NULL;
    } 
};

class LRUCache {  
public:
    
    LRUCache(int capacity) {
        cap=capacity;
        //two pointers 
        //left->indicates the least recently used nodes
        //right->indicated the most recently used nodes

        Left =new Node(0,0);
        Right =new Node(0,0);

        Left->next=Right;
        Right->prev=Left;
        
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            //if  key does not exist in the cache insert in after removing lru
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
            
            // Free allocated memory for the removed node
            delete cache[key];
        }
        cache[key] = new Node(key, value);
        insert(cache[key]);
        
        if (cache.size() > cap) {
            // remove from list & delete LRU from map
            Node* lru = Left->next;
            remove(lru);
            cache.erase(lru->k);
            
            // Free allocated memory for the removed node
            delete lru;
        }
        
    }
private:
    int cap;
    unordered_map<int,Node*>cache;
    Node*Left;
    Node*Right;

    // remove node from list
    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        
        prev->next = next;
        next->prev = prev;
    }
    // insert node at right
    void insert(Node* node) {
        Node* prev = Right->prev;
        Node* next = Right;
        
        prev->next = node;
        next->prev = node;
        
        node->prev = prev;
        node->next = next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main(){

}
