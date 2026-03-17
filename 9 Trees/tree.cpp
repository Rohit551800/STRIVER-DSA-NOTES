// REPRESENTATION AND TRAVERSAL BT DEPTH FIRST SEARCH !!
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
void Inorder (struct Node *root){
    if(root != nullptr){
        Inorder(root->left);
        cout<<root->data<<" ";
        Inorder(root->right);
    }
}
void preorder (struct Node *root){
    if(root != nullptr){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder (struct Node *root){
    if(root != nullptr){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
int main(){
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    Inorder(root);cout<<endl;
    preorder(root);cout<<endl;
    postorder(root);
}