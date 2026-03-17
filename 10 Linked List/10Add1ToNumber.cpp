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
Node* convertArr2LL(vector<int>& arr){
    int n = arr.size();
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<n;i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
Node* reverseLL(Node* head){
    Node* temp = head;
    Node* prev =nullptr;
    Node* curr = nullptr;
    while(temp != nullptr){
        curr = temp->next;
        temp->next = prev;
        prev = temp;
        temp = curr;
    }
    return prev;
}
void Traversal(Node* head){
    Node* ptr = head;
    while(ptr != nullptr){
        cout<<"|"<<ptr->data<<"|-> ";
        ptr = ptr->next;
    }
    cout<<"| NULL |";
}
Node* add1ToNumber(Node* head){
    Node* newHead = reverseLL(head);
    Node* temp = newHead;
    int carry = 1;
    while(temp != nullptr){
        int sum = temp->data + carry;
        temp->data = sum%10;
        carry = sum/10;
        if(carry == 0)break;
        if(temp->next == nullptr && carry > 0){
            Node* newNode = new Node(carry);
            temp->next = newNode;
            carry = 0;
            break;
        }
        temp = temp->next;
    }
    return reverseLL(newHead);    
}
int helper(Node* head){
    Node* temp = head;
    if(temp == nullptr) return 1;
    int carry = helper(temp->next);
    if(temp->data + carry < 10){
        return 0;
    }
    temp->data = 0;
    return 1;
}
Node* add1toNumber2(Node* head){
    int carry = helper(head);
    if(carry == 1){
        Node* newNode = new Node(carry);
        newNode->next = head;
        carry = 0;
        return newNode;
    }
    return head;
}
int main(){
    vector<int> arr = { 9 , 9 ,9 , 9};
    Node* head = convertArr2LL(arr);
    //head = add1ToNumber(head);
    head = add1toNumber2  (head);
    Traversal(head);
    return 0;
}