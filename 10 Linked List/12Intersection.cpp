#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int num;
        Node* next;
        Node(int val) {
            num = val;
            next = NULL;
        }
};
void insertNode(Node* &head,int val) {
    Node* newNode = new Node(val);
    
    if(head == NULL) {
        head = newNode;
        return;
    }
    
    Node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
    return;
}

void printList(Node* head) {
    while(head->next != NULL) {
        cout<<head->num<<"->";
        head = head->next;
    }
    cout<<head->num<<endl;
}
Node* intersectionPresent(Node* head1 , Node* head2){
    if(head1 == nullptr || head2 == nullptr)return nullptr;
    map<Node*,int>mpp;
    Node* temp = head1;
    while(temp != nullptr){
        mpp[temp] =1 ;
        temp = temp->next;
    }
    temp = head2;
    while(temp != nullptr){
        if(mpp.find(temp) != mpp.end()){
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}
Node* collionPoint(Node* head1 , Node* head2 , int diff){
    Node* temp1 = head1; 
    Node* temp2 = head2;
    for(int i = 0;i<diff;i++){
        temp1 = temp1->next;
    }
    while(temp1 != nullptr || temp2 != nullptr){
        if(temp1 == temp2) return temp1;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return nullptr;
}
Node* intersectionPoint(Node* head1 , Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    int nodes1 = 1 , nodes2 = 1;
    while(temp1 != nullptr){
        nodes1++;
        temp1 = temp1->next;
    }
    while(temp2 != nullptr){
        nodes2++;
        temp2 = temp2->next;
    }
    if(nodes1 > nodes2) return collionPoint(head1 , head2 , nodes1 - nodes2);
    else return collionPoint(head2 , head1 , nodes2 - nodes1);
}
Node* optimalSolu(Node* head1 , Node* head2){
    if(head1 == nullptr || head2 == nullptr) return nullptr;
    Node* temp1 = head1;
    Node* temp2 = head2;
    while(temp1 != temp2){
        if(temp1 == temp2) return temp1;
        if(temp1 == nullptr ) temp1 = head2;
        if(temp2 == nullptr ) temp2 = head1;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return temp2;
}
int main() {
    Node* head = NULL;
    insertNode(head,1);
    insertNode(head,3);
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,4);
    Node* head1 = head;
    head = head->next->next->next;
    Node* headSec = NULL;
    insertNode(headSec,3);
    Node* head2 = headSec;
    headSec->next = head;
    cout<<"List1: "; printList(head1);
    cout<<"List2: "; printList(head2);
    Node* answerNode = optimalSolu(head1,head2);
    if(answerNode == NULL )
    cout<<"No intersection\n";
    else
    cout<<"The intersection point is "<<answerNode->num<<endl;
    return 0;
}