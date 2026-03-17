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
Node* findMidNode(Node* head){
    if(head == nullptr || head->next == nullptr)return head;
    Node* slowp = head;
    Node* fastp = head;
    while(fastp->next != nullptr && fastp->next->next != nullptr){
        fastp = fastp->next->next;
        slowp = slowp->next;
    }
    while(fastp->next != nullptr){
        fastp = fastp->next;
        slowp = slowp->next;
    }
    return slowp;
}
void Traversal(Node* head){
    Node* ptr = head;
    while(ptr != nullptr){
        cout<<"|"<<ptr->data<<"|-> ";
        ptr = ptr->next;
    }
    cout<<"| NULL |";
}
int main(){
    vector<int> arr = { 9 , 9 ,9 , 9};
    Node* head = convertArr2LL(arr);
    //head = add1ToNumber(head);
    head = findMidNode(head);
    Traversal(head);
    return 0;
}
    