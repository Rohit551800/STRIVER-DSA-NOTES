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
vector<int> bottomView(TreeNode* root){
    vector<int>ans;
    if(root == nullptr) return ans;
    queue<pair<TreeNode*,int>> qu;
    map<int , int> mpp;
    qu.push({root , 0});
    while(!qu.empty()){
        auto p = qu.front();
        qu.pop();
        TreeNode* node = p.first;
        int x = p.second;
        if(node->left){
            qu.push({node->left , x - 1});
        }
        if(node->right){
            qu.push({node->right , x + 1});
        }
        mpp[x] = node->data;
    }
    for(auto it : mpp){
        ans.push_back(it.second);
    }
    return ans;
}
vector<int> leftView(TreeNode* root){
    vector<int> ans;
    if(root == nullptr) return ans;
    queue<pair<TreeNode* , int >> qu;
    map<int,int> mpp;
    qu.push({root , 0});
    while(!qu.empty()){
        auto p = qu.front();
        qu.pop();
        TreeNode* node = p.first;
        int x = p.second;
        if(mpp.find(x) == mpp.end()){
            mpp[x] = node->data;
        }
        if(node->left) qu.push({node->left , x+1});
        if(node->right) qu.push({node->right , x+1});
    }
    for(auto it : mpp){
        ans.push_back(it.second);
    }
    return ans;
}
vector<int> rightView(TreeNode* root){
    vector<int>ans;
    if(root == nullptr) return ans;
    queue<pair<TreeNode*,int>> qu;
    map<int , int> mpp;
    qu.push({root , 0});
    while(!qu.empty()){
        auto p = qu.front();
        qu.pop();
        TreeNode* node = p.first;
        int x = p.second;
        if(node->left){
            qu.push({node->left , x + 1});
        }
        if(node->right){
            qu.push({node->right , x + 1});
        }
        mpp[x] = node->data;
    }
    for(auto it : mpp){
        ans.push_back(it.second);
    }
    return ans;
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
    //vector<int> ans = bottomView(root);
    //vector<int> ans = leftView(root);
    vector<int> ans = rightView(root);
    for(auto it : ans){
        cout<<it<<" ";
    }
    return 0;
}