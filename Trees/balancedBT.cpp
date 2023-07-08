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

//balanced BT: at every node height(left subtree)- height(right subtree)<= 1
//naive: at every node, check for height difference
//TC: O(n*n) for traversal and finding height at each node
class Solution {
public:
    int height(TreeNode *root) {
        if(!root)  return 0;
        int lh= height(root->left);
        int rh= height(root->right);
        return 1+ max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        if(!root)   return 1;
        int lh= height(root->left);
        int rh= height(root->right);
        if(abs(lh- rh)> 1)  return 0;
        bool left= isBalanced(root->left);
        bool right= isBalanced(root->right);
        if(!left|| !right)  return 0;
        return 1;
    }
};

//optimal: reduce find height function complexity
//height of tree returned means balanced BT and if -1 received then not balanced BT
//TC: O(n), SC: O(n) for skew tree
class Solution {
public:
    int height(TreeNode *root) {
        if(!root)  return 0;
        int lh= height(root->left);
        int rh= height(root->right);
        if(lh==-1 || rh==-1)  return -1;
        if(abs(lh-rh)> 1)  return -1;
        return 1+ max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        return height(root)!=-1;
    }
};
