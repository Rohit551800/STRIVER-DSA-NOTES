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
vector<int> TopView(TreeNode* root){
    vector<int>ans;
    queue<pair<TreeNode* , int>> qu;
    map<int,int> map;
    if(root == NULL) return ans;
    qu.push({root , 0});
    while(!qu.empty()){
        auto p = qu.front();
        qu.pop();
        TreeNode* node = p.first;
        int x = p.second;
        if(map.find(x) == map.end()){
            map[x] = node->data;
        }
        if(node->left){
            qu.push({node->left , x-1});
        }
        if(node->right){
            qu.push({node->right , x + 1});
        }
    }
    for(auto it : map){
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
    root->left->right->left = new TreeNode(6);
    vector<int> ans = TopView(root);
    for(auto it : ans){
        cout<<it<<" ";
    }
    return 0;
}