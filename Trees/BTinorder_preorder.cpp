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
    TreeNode* construct(vector<int> &preorder, int prestart, int prefin, vector<int> &inorder, int instart, int infin, map<int, int> &hash) {
        if(prestart> prefin|| instart> infin)   return NULL;
        TreeNode *root= new TreeNode(preorder[prestart]);
        int rootind= hash[root->val];
        int leftno= rootind- instart;   //represents number of nodes in left subtree
        root->left= construct(preorder, prestart+ 1, prestart+ leftno, inorder, instart, rootind- 1, hash);
        root->right= construct(preorder, prestart+ leftno+ 1, prefin, inorder, rootind+ 1, infin, hash);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> hash;   //for storing inorder, saves search time for root
        for(int i=0; i<inorder.size(); i++)
            hash[inorder[i]]= i;
        TreeNode *root= construct(preorder, 0, preorder.size()- 1, inorder, 0, inorder.size()- 1, hash);
        return root;
    }
};
