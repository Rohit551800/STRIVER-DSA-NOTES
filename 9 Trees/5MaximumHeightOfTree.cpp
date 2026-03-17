// ITERATIVE TRAVERSAL DEPTH FIRST SEARCH !!
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
int maxHeight(Node* root){
    if(root == NULL) return 0;
    int lh = maxHeight(root->left);
    int rh = maxHeight(root->right);
    return 1+ max(lh , rh);
}
int minHeight(Node* root){
    if(root == NULL) return 0;
    if(root->left == NULL) return 1 + minHeight(root->right) ;
    if(root->right == NULL) return 1 + minHeight(root->left) ;
    
    return 1+min(minHeight(root->left) , minHeight(root->right));
}
int dfsHeight(Node* root){
    if(root == NULL) return 0;
    int lh = dfsHeight(root->left);
    int rh = dfsHeight(root->right);
    if(lh == -1 || rh == -1) return -1;
    if(abs(lh - rh) > 1) return -1;
    return max(lh , rh ) +1;
}
bool isBalance(Node* root){
    return dfsHeight(root) != -1;
}
int main()
{
    struct Node *root = new Node(1);
    root->right = new Node(5);
    root->right->right = new Node(7);
    root->right->right->right = new Node(7);
    //cout<<maxHeight(root);
    //cout<<minHeight(root);

    bool ans = isBalance(root);
    cout<<ans;
}