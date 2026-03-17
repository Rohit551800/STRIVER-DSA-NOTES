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
bool isPalindrome1(Node* head){
    stack<int>st;
    Node* temp = head;
    if(head == nullptr || head->next == nullptr) return true;
    while(temp != nullptr){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp != nullptr){
        if(temp->data != st.top()) return false;
        st.pop();
        temp = temp->next;
    }
    return true;
}
Node* reverseSLL(Node* head){
    if(head == nullptr || head->next == nullptr) return head;
    Node* newHead = reverseSLL(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}
bool isPalindrome2(Node* head){
    if(head == nullptr || head->next == nullptr)return true;
    Node* slowp = head;
    Node* fastp = head;
    while(fastp->next != nullptr && fastp->next->next != nullptr){
        fastp = fastp->next->next;
        slowp = slowp->next;
    }
    Node* newHead =  reverseSLL(slowp->next);
    Node* first = head;
    Node* second = newHead;
    while(second != nullptr){
        if(first->data != second->data){
            reverseSLL(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseSLL(newHead);
    return true;
}
int main(){
    vector<int> arr = { 1,2,3,3,2,1};
    Node* head = convertArr2LL(arr);
    //bool ans = isPalindrome1(head);
    bool ans = isPalindrome2(head);
    cout<< ans;
    return 0;
}