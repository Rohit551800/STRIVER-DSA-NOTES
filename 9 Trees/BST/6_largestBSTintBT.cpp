#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) : val(data), left(nullptr), right(nullptr) {};
};
class Node{
    public:
    int minVal ;
    int maxVal ;
    int maxSize;
    Node(int minVal , int maxVal ,int maxSize){
        this->minVal = minVal;
        this->maxVal = maxVal;
        this->maxSize = maxSize;
    }
};
class Solution{
    private:
    Node largestBSThelper(TreeNode* root){
        if(root == nullptr) return Node(INT_MAX , INT_MIN , 0);
        auto left  = largestBSThelper(root->left);
        auto right  = largestBSThelper(root->right);
        if(left.maxVal < root->val && right.minVal > root->val){
            return Node(min(root->val , left.maxVal) , max(root->val , right.minVal) , left.maxSize + right.maxSize + 1);
        }
        else{
            return Node(INT_MIN , INT_MAX  , max(left.maxSize , right.maxSize));
        }
    }
    public:
    int largestBSTSubtree(TreeNode* root){
        return largestBSThelper(root).maxSize;
    }
};