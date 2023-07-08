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

//brute force: find max path sum at each node
//TC: O(n^2)
class Solution {
public:
    //introduce the max path logic in height function to reduce time complexity
    //TC: O(n), SC: O(n) for skew tree, space complexity is because of the recursion stack space
    int traverse(TreeNode *root, int &maxi) {
        if(!root)  return 0;
        int leftsum= max(0, traverse(root->left, maxi));  //to manage negative values, adding these will not give me the max ans
        int rightsum= max(0, traverse(root->right, maxi)); 
        maxi= max(maxi, root->val+ leftsum+ rightsum);
        return root->val+ max(leftsum, rightsum);
    }

    int maxPathSum(TreeNode* root) {
        int maxi= root->val;
        traverse(root, maxi);
        return maxi;
    }
};
