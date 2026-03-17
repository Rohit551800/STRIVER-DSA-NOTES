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
    Node* ptr1 = head;
    while(ptr1 != nullptr){
        cout<<ptr1->data <<" ";
        ptr1 = ptr1->next;
    }
}
int lengthOfLL(Node* head){
    int counter = 0;
    Node* ptr1 = head;
    while(ptr1 != nullptr){
        ptr1 = ptr1->next;
        counter++;
    }
    return counter;
}
Node* convertArr2LL(vector<int>& arr , Node* head){
    Node* mover = head;
    for(int i = 1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
bool searchElem(Node* head , int elem){
    Node* ptr1  = head;
    while(ptr1){
        if(ptr1->data == elem)return true;
        ptr1 = ptr1->next;
    }
    return false;
}
int main(){
    vector<int>arr = { 2 , 1 , 3 , 8};
    Node* head = new Node(arr[0]);
    convertArr2LL(arr , head);
    //Traversal(head);
    // int length = lengthOfLL(head);
    // cout<<length;
    cout<<searchElem(head , 0);
    return 0;
}