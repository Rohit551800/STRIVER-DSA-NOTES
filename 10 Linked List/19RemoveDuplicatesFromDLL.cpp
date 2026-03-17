#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* prev;
    int data;
    Node* next;

    Node(int data1){
        prev = nullptr;
        data = data1;
        next = nullptr;
    }    
};
Node* convertArr2DLL(vector<int>& arr){
    int n = arr.size();
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<n;i++){
        Node* temp = new Node(arr[i]);
        temp->prev = mover;
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void Traversal(Node* head){
    Node* ptr = head;
    while(ptr != nullptr){
        cout<<"|"<<ptr->data<<"|-> ";
        ptr = ptr->next;
    }
    cout<<"| NULL |";
}
Node* removeDuplicates(Node* head){
    Node* temp = head;
    Node* nextNode = temp->next;
    while(nextNode != nullptr){
        if(temp->data != nextNode->data){
            temp->next = nextNode;
            nextNode->prev = temp;
            temp = nextNode;
        }
        nextNode = nextNode->next;
    }
    return head;
}
int main(){
    vector<int> arr = {1 , 1 , 1 , 2 , 2 , 3 , 3 , 4 , 5};
    Node* head = convertArr2DLL(arr);
    Node* ans = removeDuplicates(head);
    Traversal(head);
    return 0;
}
            