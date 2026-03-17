// Doing reverse inorder Traversal So we get the result in sorted order
#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) : val(data), left(nullptr), right(nullptr) {}
};
class solution{
public:
    int result = -1 ;
    int counter = 0;
    void inorder(TreeNode* root , int k){
        if(root == nullptr || result != -1) return ;
        inorder(root->right , k);
        counter++;
        if(counter == k){
            result = root->val;
            return;
        }
        inorder(root->left , k);
    }
    int kthSmallestNode(TreeNode* root , int k){
        inorder(root , k);
        return result;
    }
};