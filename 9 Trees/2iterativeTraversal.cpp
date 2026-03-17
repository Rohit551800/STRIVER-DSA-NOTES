// ITERATIVE TRAVERSAL DEPTH FIRST SEARCH !!
#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left ;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};
vector <int> preorder(Node *root){ // Root Left Right
    vector <int> ans;
    if(root == NULL) return ans;
    stack<Node*>st;
    st.push(root);
    while(!st.empty()){
        Node* root = st.top();
        st.pop();
        ans.push_back(root->data);
        if(root->right != NULL) st.push(root->right);
        if(root->left != NULL) st.push(root->left);
    }
    return ans;
}
vector <int> inOrder(Node *root) {   // Left Root Right
    vector<int> ans;
    if(root == NULL) return ans;
    stack <Node*> st;
    while(true){
        if(root != NULL){
            st.push(root);
            root = root->left;
        }
        else{
            if(st.empty() == true) break;
            root = st.top();
            st.pop();
            ans.push_back(root->data);
            root = root->right;
        }
    }
    return ans;
}
vector <int> postOrder1(Node* root){ //using two stack   ||Left Right Root
    vector <int> ans;
    if(root == NULL) return ans;
    stack<Node*> st1 ,st2;
    st1.push(root);
    while(!st1.empty()){
        root = st1.top();
        st1.pop();
        st2.push(root);
        if(root->left != NULL) st1.push(root->left);
        if(root->right != NULL) st1.push(root->right);
    }
    while(!st2.empty()){
        ans.push_back(st2.top()->data);
        st2.pop();
    }
}
vector <int> postOrder2(Node* root){
    vector<int>postOrder;
    if(root == NULL) return postOrder;
    stack<Node*>st;
    Node* cur = root;
    while(cur != NULL || !st.empty()){
        if(cur!=NULL){
            st.push(cur);
            cur = cur->left;
        }
        else{
            Node* temp = st.top()->right;
            if(temp == NULL){
                temp = st.top();
                st.pop();
                postOrder.push_back(temp->data);
                while(!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    postOrder.push_back(temp->data);
                }
            }
            else{
                cur = temp;
            }
        }
    }
    return postOrder;
}
int main(){
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    //vector <int> ans = preorder(root);
    //vector <int> ans = inOrder(root);
    //vector <int> ans = postOrder1(root);
    vector <int> ans = postOrder2(root);
    for(auto val : ans){
        cout<<val<<" ";
    }
    
}