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
private:
    //TC: O(n), SC: O(n)
    bool mirrorCheck(TreeNode *Left, TreeNode *Right) {
        if(!Left || !Right)  return Left==Right;
        return (Left->val== Right->val) && mirrorCheck(Left->left, Right->right)
        && mirrorCheck(Left->right, Right->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        if(!root)  return 1;
        return mirrorCheck(root->left, root->right);
    }
};
