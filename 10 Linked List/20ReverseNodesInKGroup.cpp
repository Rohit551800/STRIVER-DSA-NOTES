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
Node* findKthNode(Node* head , int k){
    Node* kthNode = head;
    int i = 1;
    while(i < k && kthNode != nullptr){
        i++;
        kthNode = kthNode->next;
    }
    return kthNode;
}
Node* reverseLL(Node* head){
    Node* prev = nullptr;
    Node* curr = nullptr;
    Node* temp = head;

    while(temp != nullptr){
        curr = temp->next;
        temp->next = prev;
        prev = temp;
        temp = curr;
    }
    return prev;   
}
Node* reverseKGroupNode(Node* head , int k){
    if(head == nullptr || k == 1)return head;
    Node* prevLast = nullptr;
    Node* temp = head;
    while(temp != nullptr){
        Node* kthNode = findKthNode(temp , k);
        if(kthNode == nullptr){
            if(prevLast){
                prevLast->next = temp;
            }
            break;
        }
        Node* nextNode = kthNode->next;
        kthNode->next = nullptr;
        reverseLL(temp);
        if(temp == head){
            head = kthNode;
        }
        else{
            prevLast->next = kthNode;
        }
        prevLast = temp;
        temp = nextNode;
    }
    return head;
}

int main(){
    vector<int> arr = { 1,2,3,4,5,6,7};
    Node* head = convertArr2LL(arr);
    head = reverseKGroupNode(head , 3);
    Traversal(head);
    return 0;
}
