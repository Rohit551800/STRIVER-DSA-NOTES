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
Node* sortLLBruteforce(Node* head){
    if(head  == nullptr || head->next == nullptr) return head;
    Node* temp = head;
    vector<int>arr;
    while(temp){
        arr.push_back(temp->data);
        temp = temp->next;
    }
    sort(arr.begin() , arr.end());
    temp = head;
    int i = 0;
    while(temp){
        temp->data = arr[i++];
        temp = temp->next;
    }
    return head;
}
Node* middleNode(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node* merge2SortedList(Node* head1 , Node* head2){
    Node* dummyNode = new Node(-1);
    Node* temp3 = dummyNode;
    while(head1 && head2){
        if(head1->data <= head2->data){
            temp3->next = head1;
            head1 = head1->next;
            temp3 = temp3->next;
        }
        else{
            temp3->next = head2;
            head2 = head2->next;
            temp3 = temp3->next;
        }
    }
    if(head1) temp3->next = head1;
    else temp3->next = head2;
    return dummyNode->next;
}
Node* mergeSort(Node* head){
    if(head == nullptr || head->next == nullptr)return head;
    Node* middle = middleNode(head);
    Node* left = head;
    Node* right = middle->next;
    middle->next = nullptr;

    left = mergeSort(left);
    right = mergeSort(right);
    return merge2SortedList(left , right);
}
int main(){
    vector<int> arr = {4 , 1 , 5 ,8 , 4 , 2 , 9};
    Node* head = convertArr2LL(arr);
    //head = sortLLBruteforce(head);
    head = mergeSort(head);
    Traversal(head);
    return 0;
}
