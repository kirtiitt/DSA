//TC: O(height), SC: O(1) except stack space
//TC better than finding LCA in BT approach
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
