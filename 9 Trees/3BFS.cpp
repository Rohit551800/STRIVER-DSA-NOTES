// Breadth first search

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
vector<vector<int>> BFS(Node* root){
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    queue<Node*> qu;
    qu.push(root);
    while(!qu.empty()){
        vector<int>level;
        int n = qu.size();
        for(int i=0;i<n;i++){
            root = qu.front();
            qu.pop();
            if(root->left != NULL) qu.push(root->left);
            if(root->right != NULL) qu.push(root->right);
            level.push_back(root->data);
        }
        ans.push_back(level);
    }
}
int main(){
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    vector<vector<int>> ans = BFS(root);
    
}