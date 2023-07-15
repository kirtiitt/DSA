//naive: storing inorder, TC: O(n), SC: O(n)

//TC: O(log n), SC: O(1)
int floorInBST(TreeNode<int> *root, int key) {
    int floor= -1;
    while(root) {
        if(root->val== key)
            return key;
        if(root->val< key) {
            floor= root->val;
            root= root->right;
        }
        else    root= root->left;
    }
    return floor;
}
