#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node* childptr;
    Node(int data1){
        data = data1;
        childptr = nullptr;
        next = nullptr;
    }
};
Node* mergeList (Node* head1 , Node* head2){
    if(head1 == nullptr && head2 == nullptr) return nullptr;
    if(head1 == nullptr) return head2;
    if(head2 == nullptr) return head1;
    Node* dummyHead = new Node(-1);
    Node* dummytemp = dummyHead;
    while(head1 && head2){
        if(head1->data <= head2->data){
            dummytemp->childptr = head1;
            head1 = head1->childptr;
            dummytemp = dummytemp->childptr;
        }
        else{
            dummytemp->childptr = head2;
            head2 = head2->childptr;
            dummytemp = dummytemp->childptr;
        }
        dummytemp->next = nullptr;   // kyuki hr ek vertical node ka next null hoga
    }
    if(head1){
        dummytemp->childptr = head1;
    }
    if(head2){
        dummytemp->childptr = head2;
    }
    return dummyHead->childptr;
}
Node* mergeAllNode(Node* head){
    if(head == nullptr || head->next == nullptr) return head;
    Node* mergeHead = mergeAllNode(head->next);
    return mergeList(head , mergeHead);
}
Node* convertArr2LL(vector<int>& arr){
    int n = arr.size();
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<n;i++){
        Node* temp = new Node(arr[i]);
        mover->childptr = temp;
        mover = temp;
    }
    return head;
}
void Traversal1(Node* head){
    if(head == nullptr)return ;
    Node* temp1 = head;
    while(temp1){
        Node* temp2 = temp1;
        while(temp2){
            cout<<"|"<<temp2->data<<"|->";
            temp2 = temp2->childptr;
        }
        temp1 = temp1->next;
    }
    cout<<"|NULL|"<<endl;
}
void Traversal2(Node* head){
    if(head == nullptr) return;
    Node* temp  = head;
    while(temp){
        cout<<"|"<<temp->data<<"|->";
        temp = temp->childptr;
    }
    cout<<"|NULL|"<<endl;
}
Node* bruteForce(Node* head){
    vector<int>arr;
    if(head == nullptr)return nullptr;
    Node* temp1 = head;
    while(temp1 != nullptr){
        Node* temp2 = temp1;
        while(temp2){
            arr.push_back(temp2->data);
            temp2 = temp2->childptr;
        }
        temp1 = temp1->next;
    }
    sort(arr.begin() , arr.end());
    head = convertArr2LL(arr);
    return head;
}
int main(){
    Node* head = new Node(3);
    Node* node2 = new Node(2);
    Node* node3 = new Node(1);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node21 = new Node(10);
    Node* node31 = new Node(7);
    Node* node32 = new Node(11);
    Node* node33 = new Node(12);
    Node* node41 = new Node(9);
    Node* node51 = new Node(6);
    Node* node52 = new Node(8);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    node2->childptr = node21;
    node3->childptr = node31;
    node31->childptr = node32;
    node32->childptr = node33;
    node4->childptr = node41;
    node5->childptr = node51;
    node51->childptr = node52;

   // Node* flattenHead = bruteForce(head);
  //  Traversal1(head);

   // Node* flattenHead = bruteForce(head);
    Node* flattenHead = mergeAllNode(head);
    Traversal2(flattenHead);
    return 0;
}
