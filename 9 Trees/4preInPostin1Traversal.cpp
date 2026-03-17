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
vector<vector<int>> Traversal(Node *root)
{
    vector<int> preOrder, inOrder, postOrder;
    vector<vector<int>>ans;
    if (root == NULL)
        return ans;
    stack<pair<Node *, int>> st;
    st.push({root, 1});
    while (!st.empty())
    {
        auto it = st.top();
        st.pop();
        if (it.second == 1)
        {
            preOrder.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->left != NULL)
            {
                st.push({it.first->left, 1});
            }
        }
        else if (it.second == 2)
        {
            inOrder.push_back(it.first->data);
            it.second++;
            st.push({it.first, it.second});

            if (it.first->right != NULL)
            {
                st.push({it.first->right, 1});
            }
        }
        else
        {
            postOrder.push_back(it.first->data);
        }
    }
    ans.push_back(preOrder);
    ans.push_back(inOrder);
    ans.push_back(postOrder);
    return ans;
}
void printVector(const vector<vector<int>> &ans) {
    for (const auto &row : ans) {
        for (const auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<vector<int>> ans = Traversal(root);
    printVector(ans);
}