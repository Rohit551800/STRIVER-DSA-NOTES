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
void Traversal(Node* head){
    Node* ptr = head;
    while(ptr){
        cout<<"| "<<ptr->data<<" |->";
        ptr = ptr->next;
    }
    cout<<"| NULL |";
}
Node* deletionAtBegining(Node* head){
    if(head == nullptr){
        cout<<"LL is already empty"<<endl;
        return nullptr;
    }
    Node* temp = head;
    head = temp->next;
    delete temp;
    return head;
}
Node* deletionAtEnding(Node* head){
    if(head == nullptr) return nullptr;
    if(head->next == nullptr){
        delete head;
        return nullptr;
    }
    Node* ptr = head;
    while(ptr->next->next != nullptr){
        ptr = ptr->next;
    }
    delete ptr->next;
    ptr->next = nullptr;
    return head;
}
Node* deletionAtPosition(Node* head , int position){
    if(head == nullptr) return nullptr;
    Node* ptr = head;
    if(position == 1){
        Node* ptr2 = head->next;
        delete head ;
        return ptr2;
    }
    int curr = 1;
    while(ptr->next != nullptr && curr < position -1 ){
        ptr = ptr->next;
        curr++;
    }
    if(ptr->next == nullptr) return head;
    Node* ptr1 = ptr->next;
    ptr->next = ptr1->next;
    delete ptr1;
    return head;
}
Node* deletionValNode(Node* head , int val){
    if(head == nullptr) return nullptr;
    if(head->data == val){
        Node* newHead = head->next;
        delete head;
        return newHead;
    }
    Node* ptr1 = head;
    Node* ptr2 = head->next;
    while(ptr2 != nullptr && ptr2->data != val){
        ptr1 = ptr2;
        ptr2 = ptr2->next;
    }
    if(ptr2 == nullptr) return head;
    ptr1->next = ptr2->next;
    delete ptr2;
    return head;    
}
int main(){
    // int position;
    // cout<<"Enter the position where you want to delete the element:";
    // cin>>position;
    int val;
    cout<<"Enter the value where you want to delete the element:";
    cin>>val;
    Node* head = new Node(5);
    Node* second = new Node(6);
    Node* third = new Node(7);
    Node* fourth = new Node(7);
    head->next =second;
    second->next = third;
    third->next = fourth;
    fourth->next = nullptr;
//    head  = deletionAtBegining(head);
//    head  = deletionAtEnding(head);
//    head  = deletionAtPosition(head  , position);
    head = deletionValNode(head , val);
    Traversal(head);
    return 0;
}