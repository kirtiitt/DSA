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

//approach 1: recursive, logic: reverse postorder
//TC: O(n), SC: O(n)
class Solution {
public:
    TreeNode *prev= NULL;
    void flatten(TreeNode* root) {
        if(!root)   return;
        flatten(root->right);
        flatten(root->left);
        root->right= prev;
        root->left= NULL;
        prev= root;
    }
};

//approach 2: iterative, using a stack- preorder
//TC: O(n), SC: O(n)
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root)   return;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()) {
            TreeNode *node= s.top();
            s.pop();
            if(node->right)    s.push(node->right);
            if(node->left)    s.push(node->left);
            if(!s.empty())    node->right= s.top();
            node->left= NULL;
        }
    }
};

//using morris traversal, SC: O(1)
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root)   return;
        TreeNode *curr= root;
        while(curr) {
            if(curr->left) {
                TreeNode *next= curr->left;
                while(next->right)
                    next= next->right;
                next->right= curr->right;
                curr->right= curr->left;
                curr->left= NULL;
            }
            curr= curr->right;
        }
    }
};
