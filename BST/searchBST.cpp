/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//recursive approach
//TC: O(log (base 2) n) i.e. height of BST, SC: O(height) for stack space
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root)    return NULL;
        if(root->val> val)    return searchBST(root->left, val);
        else if(root->val< val)    return searchBST(root->right, val);
        return root;
    }
};

//iterative approach
//TC: O(log (base 2) n), SC: O(1)
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root&& root->val!= val)
            root= val< root->val? root->left: root->right;
        return root;
    }
};
