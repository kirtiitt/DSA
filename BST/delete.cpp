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
class Solution {
public:
    //delete the node, adjust the subtrees
    //attach one subtree to another subtree for the deleted root then connect new root to parent
    //edge case: one of the subtrees doesn't exist, connect subtree directly to parent
    //TC: O(height) height i.e. log (base 2) n, SC: O(height)
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)   return NULL;
        if(root->val> key)  root->left= deleteNode(root->left, key);
        else if(root->val< key)  root->right= deleteNode(root->right, key);
        else {
            if(!root->left && !root->right)  return NULL;
            if(!root->left|| !root->right)
                return root->left? root->left: root->right;
            //attach left subtree to right
            TreeNode *temp= root->right;
            while(temp->left)
                temp= temp->left;
            temp->left= root->left;
            return root->right;
        }
        return root;
    }
};
