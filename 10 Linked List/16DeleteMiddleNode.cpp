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
Node* deleteMiddleNode(Node* head){
    if(head == nullptr || head->next == nullptr)return nullptr;
    Node* slow = head;
    Node* fast = head;
    Node* prev = nullptr;
    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }    
    prev->next = slow->next;
    delete slow;
    return head;
}
int main(){
    vector<int> arr = { 1,2,3,4,5,6};
    Node* head = convertArr2LL(arr);
    head = deleteMiddleNode(head);
    Traversal(head);
    return 0;
}