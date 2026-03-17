#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* prev;
    int data;
    Node* next;
    Node(int data1){
        prev = nullptr;
        data = data1;
        next =nullptr;
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
Node* deletionAtBegining(Node* head){
    if(head == nullptr){
        cout<<"List already empty"<<endl;
        return nullptr;
    }
    Node* temp = head;
    head = temp->next;
    head->prev = nullptr;
    delete temp;
    return head;
}
Node* deletionAtEnding(Node* head){
    if(head == nullptr){
        cout<<"List is already empty"<<endl;
        return nullptr;
    }
    Node* temp = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}
Node* deletionAtPosition(Node* head , int position){
    if(position == 1){
        Node* temp = head;
        head = temp->next;
        delete temp;
        head->prev = nullptr;
        return head;
    }
    int cur = 1;
    Node* temp = head;
    while(temp != nullptr && cur < position - 1){
        temp = temp->next;
        cur++;
    }
    if(temp->next == nullptr){
        cout<<"Position Unreachable"<<endl;
        return head;
    }
    Node* temp1 = temp->next;
    if(temp1->next == nullptr){
        temp->next = nullptr;
        delete temp1;
        return head;
    }
    temp->next = temp1->next;
    temp1->next->prev = temp;
    delete temp1;
    return head;
}
Node* deleteAtVal(Node* head , int val){
    if(head == nullptr)return nullptr;
    if(head->data == val){
        Node* temp = head;
        head = temp->next;
        delete temp;
        head->prev = nullptr;
        return head;
    }
    Node* temp = head;
    while(temp != nullptr && temp->data != val){
        temp = temp->next;
    }
    if(temp == nullptr){
        cout<<"Val not found";
        return head;
    }
    if(temp->next == nullptr){
        temp->prev->next = nullptr;
        delete temp;
        return head;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    return head;
}
int main(){
    int position;
    int val;
    // cout<<"Enter the val at which you want to delete the node:";
    // cin>>val;
    cout<<"Enter the position where you want to delete the element:";
    cin>>position;
    vector<int> arr = { 100 , 200 , 300 , 400 , 500};
    Node* head  = convertArr2DLL(arr);
//    head = deletionAtBegining(head);
//    head = deletionAtEnding(head);
    head = deletionAtPosition(head , position);
//    head = deleteAtVal(head , val);
    Traversal(head);
    return 0;
}