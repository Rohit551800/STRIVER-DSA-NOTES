#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) : val(data), left(nullptr), right(nullptr) {};
};
class BSTIterator{
    public:
    stack<TreeNode*>mystack;
    bool reverse = false;
    BSTIterator(TreeNode* root , bool isReverse){
        pushAll(root);
    }
    bool hasnext(){
        return !mystack.empty();
    }
    int next(){
        TreeNode* node = mystack.top();
        mystack.pop();
        if(!reverse) pushAll(node->right); // next 
        else pushAll(node->left); // before
        return node->val;
    }
    void pushAll(TreeNode* root){
        while(root == nullptr){
            mystack.push(root);
            if(reverse == true){
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
    }
};
class Solution{
    bool findTarger(TreeNode* root , int sum){
        if(!root) return false;
        BSTIterator l(root , false);
        BSTIterator r(root , true);
        int i = l.next();
        int j = r.next();
        while(i<j){
            if(i+j == sum) return true;
            else if (i+j > sum) j = r.next();
            else i = l.next();
        }
        return false;
    }
};