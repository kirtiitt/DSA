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
    void traverse(TreeNode* root, int &ans, int &prev) {
        if(!root)   return;
        traverse(root->left, ans, prev);
        ans= min(ans, abs(prev- root->val));
        prev= root->val;
        traverse(root->right, ans, prev);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        //inorder traversal- gives sorted order
        //sorted order gives me the min diff between elements eliminating the complexity O(n^2)
        int ans= INT_MAX, prev= INT_MAX/2;  //divide by 2 to manage overflow
        traverse(root, ans, prev);
        return ans;
    }
};
