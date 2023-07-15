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

//approach 1: check in inorder traversal, don't store the inorder but check while traversing
//TC: O(n), SC: O(height)
class Solution {
public:
    void traverse(TreeNode *root, long &prev, bool &flag) {
        if(!root)   return;
        traverse(root->left, prev, flag);
        if(prev>= root->val) {
            flag= false;
            return;
        }
        prev= root->val;
        traverse(root->right, prev, flag);
    }

    bool isValidBST(TreeNode* root) {
        if(!root->left && !root->right)  return true;
        bool flag= true;
        long prev= LONG_MIN;
        traverse(root, prev, flag);
        return flag;
    }
};

//approach 2: assign a range in which the node should exist, max and min
//TC: O(n), SC:O(height)
class Solution {
public:
    bool traverse(TreeNode *root, long min, long max) {
        if(!root)   return true;
        if(root->val>= max|| root->val<=min)    return false;
        return traverse(root->left, min, root->val) && traverse(root->right, root->val, max);
    }

    bool isValidBST(TreeNode* root) {
        return traverse(root, LONG_MIN, LONG_MAX);
    }
};
