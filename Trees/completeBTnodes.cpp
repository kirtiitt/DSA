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

//TC: O(log n* log n) for traverse and height resp, SC: O(log n)
class Solution {
public:
    bool height(TreeNode *root, int level) {
        TreeNode *lh= root, *rh= root;
        while(lh && rh) {
            level++;
            lh= lh->left;
            rh= rh->right;
            if(!lh || !rh)  return false;
        }
        return true;
    }

    int countNodes(TreeNode* root) {
        if(!root)   return 0;
        int level;
        return height(root, level)? (1<<level)- 1: 1+ countNodes(root->left)+ countNodes(root->right);
    }
};
