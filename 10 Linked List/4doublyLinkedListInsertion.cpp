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
Node* insertionAtBegining(Node* head , int data){
    if(head == nullptr){
        return new Node(data);
    }
    Node* newNode = new Node(data);
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}
Node* insertionAtEnding(Node* head , int data){
    if(head == nullptr)return new Node(data);
    Node* newNode = new Node(data);
    Node* ptr1 = head;
    while(ptr1->next){
        ptr1 = ptr1->next;
    }
    ptr1->next = newNode;
    newNode->prev = ptr1;
    return head;
}
Node* insertionAtPosition(Node* head , int data , int position){
    if(position == 1){
        Node* newNode = new Node(data);
        newNode->next = head ;
        head->prev = newNode;
        return newNode;
    }
    Node* newNode = new Node(data);
    Node* ptr1 = head;
    int cur = 1;
    while(ptr1->next != nullptr && cur < position - 1){
        ptr1 = ptr1->next;
        cur++;
    }
    if(ptr1 == nullptr) return head;
    if(ptr1->next == nullptr){
        ptr1->next = newNode;
        newNode->prev = ptr1;
        return head;
    }
    newNode->next = ptr1->next;
    ptr1->next->prev = newNode;
    newNode->prev = ptr1;
    ptr1->next = newNode;
    return head;
}
Node* insertionAfterElement(Node* head , int data , int val){
    if(head == nullptr)return nullptr;
    Node* ptr = head;
    while(ptr != nullptr && ptr->data != val){
        ptr = ptr->next;
    }
    if(ptr == nullptr) return head;
    Node* newNode = new Node(data);
    newNode->next = ptr->next;
    newNode->prev = ptr;
    ptr->next = newNode;
    return head;
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
Node* removeNthNode(Node* head , int n){
    if(head == nullptr)return nullptr;
    if(n == 1 && head->next == nullptr)return nullptr;
    Node* temp = head;
    int totalNode = 1;
    while(temp->next != nullptr){
        totalNode++;
        temp = temp->next;
    }
    if(n>totalNode)return head;
    int position = totalNode - n + 1;
    if(position == 1){
        Node* newHead = head->next;
        delete head;
        return newHead;
    }
    temp = head;
    int curr = 1;
    while(temp != nullptr && curr < position - 1){
        curr++;
        temp = temp->next;
    }
    Node* ptr = temp->next;
    temp->next = ptr->next;
    delete ptr;
    return head;
}
Node* removeLastNthNode(Node* head , int n){
    if(head == nullptr)return nullptr;
    Node* fastp = head;
    Node* slowp = head;
    for(int i=0;i<n;i++){
        fastp = fastp->next;
    }
    if(fastp == nullptr){
        Node* temp = head;
        head = temp->next;
        delete temp;
        return head;
    }
    while(fastp->next != nullptr){
        slowp = slowp->next;
        fastp = fastp->next;
    }
    Node* delNode = slowp->next;
    slowp->next = delNode->next;
    delete delNode;
    return head;
}
int main(){
    // int data;
    // cout<<"Enter the data you want to insert:";
    // cin>>data;
    // int position;
    // int val;
    // cout<<"Enter the value after which you want to insert element:";
    // cin>>val;
    // cout<<"Enter the position to insert the value:";
    // cin>>position;
    int k;
    cout<<"Enter the value of K";
    cin>>k;
    vector<int> arr = { 0 , 1 , 1 , 0 , 2 , 0 , 2 , 1};
    Node* head = convertArr2DLL(arr);
//    head = insertionAtBegining(head , data);
//    head = insertionAtEnding(head , data);
//    head = insertionAtPosition(head , data , position);
//    head = insertionAfterElement(head , data , val);
    //head = sort012Approach1(head);
    //head = sort012Approach2(head);
//    head = sort012Approach3(head);
    //head = removeNthNode(head , k);
    head = removeLastNthNode(head , k);
    Traversal(head);
    return 0;
}