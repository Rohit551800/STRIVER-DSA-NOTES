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
void childrenSum(TreeNode* root){
    if(root == nullptr) return;
    int child = 0;
    if(root->left){
        child += root->left->data;
    }
    if(root->right){
        child += root->right->data;
    }
    if(child >= root->data){
        root->data = child;
    }
    else{
        if(root->left){
            root->left->data = root->data;
        }
        else if(root->right){
            root->right->data = root->data;
        }
    }
    childrenSum(root->left);
    childrenSum(root->right);
    int total = 0;
    if(root->left) total += root->left->data;
    if(root->right) total += root->right->data;
    if(root->left || root->right) root->data = total;

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
}