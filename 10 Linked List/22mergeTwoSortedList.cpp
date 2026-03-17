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
Node* optimalSolu (Node* head1 , Node* head2){
    if(head1 == nullptr && head2 == nullptr) return nullptr;
    if(head1 == nullptr)return head2;
    if(head2 == nullptr)return head1;
    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* dummyNode = new Node(-1);
    Node* newHead = dummyNode;
    while(temp1 && temp2){
        if(temp1->data <= temp2->data){
            dummyNode->next = temp1;
            temp1 = temp1->next;
            dummyNode = dummyNode->next;
        }
        else{
            dummyNode->next = temp2;
            temp2 = temp2->next;
            dummyNode = dummyNode->next;
        }
    }
    while(temp1){
        dummyNode->next = temp1;
        temp1 = temp1->next;
        dummyNode = dummyNode->next;
    }
    while(temp2){
        dummyNode->next = temp2;
        temp2 = temp2->next;
        dummyNode = dummyNode->next;
    }
    return newHead->next;
}
int main(){
    vector<int> arr1 = {1 , 2 , 3 , 4 , 5 , 6 , 8};
    vector<int> arr2 = { 4 , 7 , 9 , 11 , 12 , 13};
    Node* head1 = convertArr2LL(arr1);
    Node* head2 = convertArr2LL(arr2);
    Node* finalNode = optimalSolu(head1 , head2);
    Traversal(finalNode);
    return 0;
}
