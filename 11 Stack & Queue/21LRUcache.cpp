#include<bits/stdc++.h>
using namespace std;
class LRUcache{
    public:
    class Node{
        public:
        int key;
        int data;
        Node* prev;
        Node* next;
        Node(int key1 , int val){
            key = key1;
            data = val;
            prev = nullptr;
            next = nullptr;
        }
    };
    int capacity;
    unordered_map <int , Node*> mpp;
    Node* head = new Node(-1 , -1);
    Node* tail = new Node(-1 , -1);
    LRUcache(int size){
        capacity = size;
        head->next = tail;
        tail->prev = head;
    }
    void insertionAtBegining(Node* node){
        Node* ptr = head->next;
        node->next = ptr;
        ptr->prev = node;
        head->next = node;
        node->prev = head;
    }
    void deleteNode(Node* node){
        Node* delprev = node->prev;
        Node* delnext = node->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    int get(int key){
        if(mpp.find(key) != mpp.end()){
            Node* node = mpp[key];
            int val = node->data;      
            deleteNode(node);
            insertionAtBegining(node);
            return val;
        }
        return -1;
    }
    void put(int key , int value){
        if(mpp.find(key) != mpp.end()){
            Node* resNode = mpp[key];
            resNode->data = value;
            deleteNode(resNode);
            insertionAtBegining(resNode);
        }
        else{
            if(mpp.size() == capacity){
                Node* node = tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
                delete node;
            }
            Node* newNode = new Node(key , value);
            mpp[key] = newNode;
            insertionAtBegining(newNode);
        }
    }
};
int main(){

    LRUcache lru(2);  // capacity = 2

    lru.put(1, 10);   // cache = {1=10}
    lru.put(2, 20);   // cache = {1=10, 2=20}

    cout << "Get 1: " << lru.get(1) << endl;  // returns 10, cache = {2=20, 1=10}

    lru.put(3, 30);   // capacity full → remove LRU key=2, cache = {1=10, 3=30}

    cout << "Get 2: " << lru.get(2) << endl;  // returns -1 (not found)

    lru.put(4, 40);   // remove key=1, cache = {3=30, 4=40}

    cout << "Get 1: " << lru.get(1) << endl;  // returns -1
    cout << "Get 3: " << lru.get(3) << endl;  // returns 30
    cout << "Get 4: " << lru.get(4) << endl;  // returns 40
    return 0;
}