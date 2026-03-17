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
void Traversal(Node* head){
    Node* ptr = head;
    while(ptr != nullptr){
        cout<<"|"<<ptr->data<<"|-> ";
        ptr = ptr->next;
    }
    cout<<"| NULL |";
}
Node* reverseLLAproach1(Node* head){
    stack<int>st;
    Node* temp = head;
    while(temp != nullptr){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(!st.empty()){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}
Node* reverseLLAproach2(Node* head){
    Node* temp = head;
    Node* prev = nullptr;
    Node* curr = nullptr;
    while(temp != nullptr){
        curr = temp->next;
        temp->next = prev;
        prev = temp;
        temp = curr;
    }
    return prev;
}
Node* reverseLLRecursive1(Node* head){
    if(head == nullptr || head->next == nullptr)return head;
    Node* newHead = reverseLLRecursive1(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}
int main(){
    vector<int> arr = { 1,2,3,4,5,6};
    Node* head = convertArr2LL(arr);
    //head = reverseLLAproach1(head);
   // head = reverseLLAproach2(head);
    head = reverseLLRecursive1(head);
    Traversal(head);
    return 0;
}