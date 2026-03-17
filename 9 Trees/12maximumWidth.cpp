#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
int maximumWidth(TreeNode* root){
    int width = 0;
    if(root == nullptr) return width;
    queue<pair<TreeNode* , int>> qu;
    qu.push({root , 0});
    while(!qu.empty()){
        int minn = qu.front().second;
        int n = qu.size();
        int first , last;
        for(int i =0;i<n;i++){
            int cur_id = qu.front().second - minn;
            TreeNode* root = qu.front().first;
            qu.pop();
            if(i == 0) first = cur_id;
            if(i == n-1) last = cur_id;
            if(root->left) qu.push({root->left , cur_id*2+1});
            if(root->right) qu.push({root->right , cur_id*2+2});
        }
        width = max(width , last - first +1);
    }
    return width;
}
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(7);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->left->right->left = new TreeNode(8);
    root->left->right->right = new TreeNode(9);
    int ans = maximumWidth(root);
    cout<< ans;
}


TreeNode* findLastRight(TreeNode* root){
    if(root->right == nullptr) return root;
    return findLastRight(root->right);   
}
TreeNode* helper(TreeNode* root){
    if(root->left == nullptr) return root->right;
    if(root->right == nullptr) return root->left;
    TreeNode* rightChild = root->right;
    TreeNode* lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
} 
