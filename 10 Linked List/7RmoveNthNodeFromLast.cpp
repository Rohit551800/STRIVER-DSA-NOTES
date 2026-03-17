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
Node* removeNthNode(Node* head , int n){
    if(head == nullptr)return nullptr;
    if(n == 1 && head->next == nullptr)return nullptr;
    Node* temp = head;
    int totalNode = 1;
    while(temp->next != nullptr){
        totalNode++;
        temp = temp->next;
    }
    if(n>totalNode)return head;
    int position = totalNode - n + 1;
    if(position == 1){
        Node* newHead = head->next;
        delete head;
        return newHead;
    }
    temp = head;
    int curr = 1;
    while(temp != nullptr && curr < position - 1){
        curr++;
        temp = temp->next;
    }
    Node* ptr = temp->next;
    temp->next = ptr->next;
    delete ptr;
    return head;
}
Node* removeLastNthNode(Node* head , int n){
    if(head == nullptr)return nullptr;
    Node* fastp = head;
    Node* slowp = head;
    for(int i=0;i<n;i++){
        fastp = fastp->next;
    }
    if(fastp == nullptr){
        Node* temp = head;
        head = temp->next;
        delete temp;
        return head;
    }
    while(fastp->next != nullptr){
        slowp = slowp->next;
        fastp = fastp->next;
    }
    Node* delNode = slowp->next;
    slowp->next = delNode->next;
    delete delNode;
    return head;
}
int main(){
    int k;
    cout<<"Enter the value of K";
    cin>>k;
    vector<int> arr = { 0 , 1 , 1 , 0 , 2 , 0 , 2 , 1};
    Node* head = convertArr2DLL(arr);
    removeNthNode(head , k);
    removeLastNthNode(head , k);
    Traversal(head);
    return 0;
}