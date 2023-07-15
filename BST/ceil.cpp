//naive: store inorder and then find ceil
//TC: O(n), SC: O(n)

//TC: O(log n) (log base 2), SC: O(1)
//iterative
int findCeil(BinaryTreeNode<int> *root, int key) {
    int ceil= -1;
    while(root) {
        if(root->data== key)
            return key;
        else if(root->data> key) {
            ceil= root->data;
            root= root->left;
        }
        else    root= root->right;
    }
    return ceil;
}

//recursive
//SC: O(log n) based on height for stack space
void solve(BinaryTreeNode<int> *root, int key, int &ceil) {
    if(!root)   return;
    if(root->data== key) {
        ceil= root->data;
        return;
    }
    if(root->data> key) {
        ceil= root->data;
        solve(root->left, key, ceil);
    }
    else    solve(root->right, key, ceil);
}

int findCeil(BinaryTreeNode<int> *root, int key) {
    int ceil= -1;
    solve(root, key, ceil);
    return ceil;
}
