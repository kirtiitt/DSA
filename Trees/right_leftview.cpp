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

//approach 1: level order traversal where the first element at each level gives left view and last element gives right view
//TC: O(n), SC: O(n)

class Solution {
public:
    //approach 2: recursive
    //intuition: for right view use reverse preorder (root, R, L) and for left view use preorder
    //TC: O(n), SC: O(n)
    void reversePreOrder(TreeNode *root, int level, vector<int> &ans) {
        if(!root)   return;
        if(level== ans.size())   ans.push_back(root->val);
        if(root->right)   reversePreOrder(root->right, level+1, ans);
        if(root->left)   reversePreOrder(root->left, level+1, ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        reversePreOrder(root, 0, ans);
        return ans;
    }
};
