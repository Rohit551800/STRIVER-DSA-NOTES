#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) : val(data), left(nullptr), right(nullptr) {};
};
class Solution{
    private:
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;

    void inorder(TreeNode* root , TreeNode* prev){
        if(root == nullptr)return ;
        inorder(root , prev);
        while(prev != nullptr && root->val < prev->val){
            if(first == nullptr){
                prev = nullptr;
                root = middle;
            }
            else{
                root = last;
            }
        }
        prev = root;
        inorder(root->right, prev);
    }
    void  recoverBST(TreeNode* root){
        if(root == nullptr)return;
        first = middle = last = nullptr;
        TreeNode* prev = new TreeNode(INT_MIN);
        inorder(root , prev);
        if(first && middle) swap(first , middle);
        else if(first && last) swap(first , last);
    }
};