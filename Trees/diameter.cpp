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

//naive: find height of subtrees at each node, add them and the max one is ans
//TC: O(n^2)
class Solution {
public:
    int height(TreeNode *node) {
        if(!node)  return 0;
        int lh= height(node->left);
        int rh= height(node->right);
        return 1+ max(lh, rh);
    }

    int maxi= INT_MIN;
    int diameterOfBinaryTree(TreeNode* root) {
        int lh= height(root->left);
        int rh= height(root->right);
        maxi= max(maxi, lh+ rh);
        if(root->left)  diameterOfBinaryTree(root->left);
        if(root->right) diameterOfBinaryTree(root->right);
        return maxi;
    }
};

//optimal: calculate max by addition of subtrees in the height function itself
//TC: O(n), SC: O(n)
class Solution {
public:
    int height(TreeNode *node, int &maxi) {
        if(!node)  return 0;
        int lh= height(node->left, maxi);
        int rh= height(node->right, maxi);
        maxi= max(maxi, lh+rh);
        return 1+ max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxi= INT_MIN;
        height(root, maxi);
        return maxi;
    }
};
