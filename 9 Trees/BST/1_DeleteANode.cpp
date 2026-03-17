#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) : val(data), left(nullptr), right(nullptr) {}
};
TreeNode* deleteNode(TreeNode* root ,int key){
    if(root == nullptr) return nullptr;
    TreeNode* dummy = root;
    if(root->val == key) return helper(root);
    while(root){
        if(root->val > key){
            if(root->left != nullptr && root->left->val == key){
                root->left = helper(root->left);
                break;
            }
            else{
                root = root->left;
            }
        }
        else{
            if(root->right != nullptr && root->right->val == key){
                root->right = helper(root->right);
                break;
            }
            else{
                root = root->right;
            }
        }
    }
    return dummy;
}
TreeNode* helper(TreeNode* root){
    if(root->left == nullptr) return root->right;
    if(root->right == nullptr) return root->left;
    TreeNode* rightChild = root->right;
    TreeNode* lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}
TreeNode* findLastRight(TreeNode* root){
    if(root->right == nullptr) return root;
    while(root->right != nullptr){
        root = root->right;
    }
}