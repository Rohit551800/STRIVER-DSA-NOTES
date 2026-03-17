#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};
Node* insertionInBegining(Node* head  , int data){
    if(head == nullptr){
        head = new Node(data);
        return head;
    }
    else{
        Node* ptr = head;
        Node* newNode = new Node(data);
        newNode->next = ptr;
        return newNode;
    }
}
Node* insertionInEnding(Node* head , int data){
    if(head == nullptr) return new Node(data);
    Node* newNode = new Node(data);
    Node* ptr = head;
    while(ptr->next){
        ptr = ptr->next; 
    }
    ptr->next = newNode;
    newNode->next = nullptr;
    return head;
}
Node* insertionAtPosition(Node* head , int data , int position){
    Node* newNode = new Node(data);
    if(position == 1){
        newNode->next = head;
        return newNode;
    }
    int curr = 1;
    Node* ptr = head;
    while(ptr->next != nullptr && curr < position-1){
        ptr = ptr->next;
        curr++;
    }
    if(ptr == nullptr) return head;
    newNode->next = ptr->next;
    ptr->next = newNode;
    return head;
}
Node* insertionAfterValue(Node* head , int data , int val){
    Node* newNode = new Node(data);
    Node* ptr = head;
    while(ptr->next != nullptr && ptr->data != val){
        ptr = ptr->next;
    }
    if(ptr == nullptr) return head;
    newNode->next = ptr->next ;
    ptr->next = newNode;
    return head;
}
void Traversal(Node* head){
    Node* ptr = head;
    while(ptr){
        cout<<"| "<<ptr->data<<" |->";
        ptr = ptr->next;
    }
    cout<<"| NULL |";
}
int main(){
    int n;
    cout<<"Enter the element to insert :";
    cin>>n;
    // int position;
    // cout<<"Enter the position to insert the element:";
    // cin>>position;
    int val;
    cout<<"Enter the value after which you want to inset the Node:";
    cin>>val;
    Node* head = new Node(5);
    Node* second = new Node(6);
    Node* third = new Node(7);
    Node* fourth = new Node(7);
    head->next =second;
    second->next = third;
    third->next = fourth;
    fourth->next = nullptr;
//    Traversal(insertionInBegining(head , n));
//    Traversal(insertionInEnding(head , n));
//    Traversal(insertionAtPosition(head , n , position));
    Traversal(insertionAfterValue(head , n , val));
return 0;
}