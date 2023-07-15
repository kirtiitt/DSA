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

 //TC: O(n* logn) for traversal and finding, SC: O(n) for hashing inorder
class Solution {
public:
    TreeNode* construct(vector<int> &postorder, int postst, int postfin, vector<int> &inorder, int instart, int infin, map<int, int> &hash) {
        if(postst> postfin|| instart> infin)    return NULL;
        TreeNode *root= new TreeNode(postorder[postfin]);
        int rootind= hash[root->val];
        int leftno= rootind- instart;
        root->left= construct(postorder, postst, postst+ leftno- 1, inorder, instart, rootind- 1, hash);
        root->right= construct(postorder, postst+ leftno, postfin- 1, inorder, rootind+ 1, infin, hash);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> hash;
        for(int i=0; i<inorder.size(); i++)
            hash[inorder[i]]= i;
        TreeNode *root= construct(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()- 1, hash);
        return root;
    }
};
