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
Node* deleteOccurence(Node* head , int key){
    if(head == nullptr) return nullptr;
    Node* temp = head;

    while(temp != nullptr){
        if(temp->data == key){
            Node* nextNode = temp->next;
            Node* prevNode = temp->prev;

            if(temp == head){
                head = nextNode;
                if(head) head->prev = nullptr;
            } else {
                if(prevNode) prevNode->next = nextNode;
                if(nextNode) nextNode->prev = prevNode;
            }

            delete temp;
            temp = nextNode;
        }
        else {
            temp = temp->next;
        }
    }
    return head;
}

int main(){
    vector<int> arr = {10 , 4 , 10 , 10 , 6 , 10};
    Node* head = convertArr2DLL(arr);
    Node* ans  = deleteOccurence(head , 10);
    Traversal(ans);
    return 0;
}
            