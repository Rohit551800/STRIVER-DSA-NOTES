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
vector<vector<int>> findPairSum(Node* head , int sum){
    vector<vector<int>> ans;
    if(head == nullptr || head->next == nullptr)return ans;
    Node* temp1 = head;
    while(temp1 != nullptr){
        Node* temp2 = temp1->next;
        while(temp2 != nullptr && temp1->data + temp2->data <=sum){
            if(temp1->data + temp2->data == sum){
                ans.push_back({temp1->data , temp2->data});
            }
            else if(temp1->data + temp2->data > sum){
                break;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return ans;
}
Node* findTail(Node* head){
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    return temp;
}
vector<vector<int>> optimalSolu(Node* head , int sum){
    vector<vector<int>> ans;
    if(head == nullptr || head->next == nullptr)return ans;
    Node* left = head;
    Node * right = findTail(head);
    while(left->data < right->data){
        if(left->data + right->data > sum){
            right = right->prev;
        }
        else if(left->data + right->data < sum){
            left = left->next;
        }
        else{
            ans.push_back({left->data , right->data});
            left = left->next;    
            right = right->prev;
        }
    }
    return ans;
}
int main(){
    vector<int> arr = {1 , 2 , 3 , 4 , 9};
    Node* head = convertArr2DLL(arr);
    //vector<vector<int>> ans  = findPairSum(head , 5);
    vector<vector<int>> ans  = optimalSolu(head , 5);
    for(auto it : ans){
        for(auto result: it){
            cout<<result<<" ";
        }
        cout<<endl;
    }
    return 0;
}
            