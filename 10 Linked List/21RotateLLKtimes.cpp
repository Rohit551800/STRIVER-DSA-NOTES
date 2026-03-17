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
Node* bruteforce(Node* head , int k){
    Node* temp = head;
    vector<int>vec;
    while(temp){
        vec.push_back(temp->data);
        temp = temp->next;
    }
    int n = vec.size();
    int firstHalf = n-k;;
    reverse(vec.begin() , vec.begin() + firstHalf);
    reverse(vec.begin() + firstHalf , vec.end());
    reverse(vec.begin() , vec.end());
    temp = head;
    int i = 0;
    while(temp){
        temp->data = vec[i++];
        temp = temp->next;
    }
    return head;
}
Node* optimalSolu(Node* head , int k){
    Node* temp = head;
    int counter = 1;
    while(temp->next != nullptr){
        counter++;
        temp = temp->next;
    }
    temp->next = head;
    int n = counter - k;
    while(n--){
        temp = temp->next;
    }
    head = temp->next;
    temp->next = nullptr;
    return head;
}
int main(){
    vector<int> arr = {1,2,3,4,5};
    Node* head = convertArr2LL(arr);
    //head = bruteforce(head , 2);
    head = optimalSolu(head , 2);
    Traversal(head);
    return 0;
}
