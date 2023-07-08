/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//brute force: find path for both nodes and store it, then find the first common node in the stored paths
//TC: O(n+ n)+ O(n) (for finding 2 paths and then finding lca), SC: O(n+ n) for storing path
class Solution {
public:
    //TC: O(n), SC: O(n)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root|| root==p|| root==q)  return root;
        TreeNode *left, *right;
        left= lowestCommonAncestor(root->left, p, q);
        right= lowestCommonAncestor(root->right, p, q);
        if(!left)  return right;
        else if(!right)  return left;
        else  return root;  //both left and right exists which means the root is first common
    }
};
