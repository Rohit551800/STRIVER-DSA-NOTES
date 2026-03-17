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
Node* sort012Approach1(Node* head){
    Node* temp = head;
    int counter1 = 0, counter2 = 0, counter3 = 0;
    while(temp != nullptr){
        if(temp->data == 0)counter1++;
        else if(temp->data == 1)counter2++;
        else counter3++;
        temp = temp->next;
    }
    temp = head;
    while(counter1--){
        temp->data = 0;
        temp = temp->next;
    }
    while(counter2--){
        temp->data = 1;
        temp = temp->next;
    }
    while(counter3--){
        temp->data = 2;
        temp = temp->next;
    }
    return head;
}
Node* sort012Approach2(Node* head){
    Node* low = head;
    Node* mid = head;
    Node* high = head;
    while(high->next != nullptr){
        high = high->next;
    }
    while(mid != high){
        if(mid->data == 0){
            swap(mid->data , low->data);
            low = low->next;
            mid = mid->next;
        }
        else if(mid->data == 1){
            mid = mid->next;
        }
        else{
            swap(mid->data , high->data);
            high = high->prev;
        }
    }
    return head;
}
Node* sort012Approach3(Node* head){
    Node* zerodummy = new Node(-1);
    Node* onedummy = new Node(-1);
    Node* twodummy = new Node(-1);
    Node* zero = zerodummy;
    Node* one = onedummy;
    Node* two = twodummy;
    Node* temp = head;
    while(temp != nullptr){
        if(temp->data == 0){
            zero->next = temp;
            zero = zero->next;
        }
        else if(temp->data == 1){
            one->next = temp;
            one = one->next;
        }
        else{
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }
    zero->next = onedummy->next?onedummy->next:twodummy->next;;
    one->next = twodummy->next;
    two->next = nullptr;
    Node* newHead = zerodummy->next;
    delete zerodummy;
    delete onedummy;
    delete twodummy;
    return newHead;
}
int main(){
    vector<int> arr = { 0 , 1 , 1 , 0 , 2 , 0 , 2 , 1};
    Node* head = convertArr2DLL(arr);
    //head = sort012Approach1(head);
    //head = sort012Approach2(head);
    head = sort012Approach3(head);
    Traversal(head);
    return 0;
}