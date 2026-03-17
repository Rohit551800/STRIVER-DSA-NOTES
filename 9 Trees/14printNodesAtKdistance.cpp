TreeNode* buildTree(vector<int>& postOrder , int postStart , int postEnd 
    vector<int>& inOrder , int inStart , int inEnd , map<int,int>& map){
        if(postStart > postEnd || inStart > inEnd) return nullptr;
        TreeNode* root = new TreeNode(postOrder[postEnd]);
        int inRoot = map[root->val];
        int numsLeft = inRoot - inStart;

        root->left = buildTree(postOrder , postStart , postStart+numsLeft-1 , 
            inOrder , inStart , inRoot-1 , map);
        root->right = buildTree(postOrder ,postStart+numsleft ,postEnd-1. inorder , inRoot+1 , inEnd , map);

        return root;
    }



TreeNode* BuildTree(vector<int>& postOrder , vector<int>& inOrder){
    map<int,int>map;
    int size = inOrder.size();
    for(int i=0;i<size;i++){
        map[inOrder[i]] = i;
    }
    TreeNode* root = buildTree(postOrder , 0 , postOrder.size() - 1
    inOrder , 0 , inOrder.size() - 1 , map);
}