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
Node* bruteforce(vector<Node*>& list1){
    int n = list1.size();
    vector<int> arr;
    for(auto it:list1){   
        while(it){
            arr.push_back(it->data);
            it = it->next;
        }
    }
    
    sort(arr.begin() , arr.end());
    Node* newHead = convertArr2LL(arr);
    return newHead;
}
Node* merge2SortedList(Node* head1 , Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;

    Node* dummyNode = new Node(-1);
    Node* temp3 = dummyNode;
    while(temp1 && temp2){
        if(temp1->data <= temp2->data){
            temp3->next = temp1;
            temp1 = temp1->next;
            temp3 = temp3->next;
        }
        else{
            temp3->next = temp2;
            temp2 = temp2->next;
            temp3 = temp3->next;
        }
    }
    if(temp1) temp3->next = temp1;
    else temp3->next = temp2;
    return dummyNode->next;
}
Node* betterSolu(vector<Node*>& list){
    int n = list.size();
    Node* head = list[0];
    for(int i=1;i<n;i++){
        head =  merge2SortedList(head , list[i]);
    }
    return head;
}
int main(){
    vector<vector<int>> input1 = {{1,4,5}, {1,3,4}, {2,6}};
    vector<Node*> lists1;
    for (auto &v : input1) lists1.push_back(convertArr2LL(v));
  //Node* ans1 = bruteforce(lists1);
    Node* ans1 = betterSolu(lists1);
    cout << "Example 1 Output: ";
    Traversal(ans1);

//     // Example 2
//     vector<vector<int>> input2 = {};
//     vector<Node*> lists2;
//     for (auto &v : input2) lists2.push_back(convertArr2LL(v));
//    // Node* ans2 = mergeKLists(lists2);
//     cout << "Example 2 Output: ";
//     Traversal(ans2);

//     // Example 3
//     vector<vector<int>> input3 = {{}};
//     vector<Node*> lists3;
//     for (auto &v : input3) lists3.push_back(convertArr2LL(v));
//     Node* ans3 = mergeKLists(lists3);
//     cout << "Example 3 Output: ";
//     Traversal(ans3);

}
