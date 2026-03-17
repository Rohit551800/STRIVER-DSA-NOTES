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
int diameter = 0;
int maxPath(Node* root){
    if(root == nullptr) return 0;
    int lh = maxPath(root->left);
    int rh = maxPath(root->right);
    diameter = max(diameter , lh+rh);
    return 1 + max (rh , lh);
}
int findDiameter(Node* root){
    maxPath(root);
    return diameter;
}

// Maximum Path Sum
int maxPath1 = INT_MIN;
int maxPathSum(Node* root){
    if(root == nullptr) return 0;
    int leftSum = max(0,maxPathSum(root->left));
    int rightSum = max(0,maxPathSum(root->right));
    maxPath1 = max(maxPath1 , leftSum + rightSum + root->data);
    return root->data + max(leftSum , rightSum);
}
int returnPath(Node* root){
    maxPathSum(root);
    return maxPath1;
}
int main()
{
    struct Node *root = new Node(1);
    root->right = new Node(5);
    root->right->right = new Node(7);
    root->right->right->right = new Node(7);
    //cout<<maxHeight(root);
    //cout<<minHeight(root);
    int diameter = returnPath(root);
    
    cout<<diameter;
}




// code of top view
/*
vector <int> topView(TreeNode* root){
    queue<pair<TreeNode* , int>> qu;
    map<int,int> map;
    qu.push({root , 0});
    while(!qu.empty()){
        auto p = qu.front();
        qu.pop();
        TreeNode* node = p.first;
        int x = p.second;
        if(map.find(x) == map.end()){
            map[x] node->val;
        }
        if(node->left){
            qu.push({node->left , x - 1});
        }
        if(node->right){
            qu.push({node->right , x + 1});
        }
    }
        vector<int> ans;
        for(auto it : map){
            ans.push_back(it.second);
        }
}


*/

