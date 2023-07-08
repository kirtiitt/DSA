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
    //height of a tree or max depth
    //TC: O(n), SC: O(n)
    //approach 1: recursive
    int maxDepth(TreeNode* root) {
        if(root== NULL)  return 0;
        int lefth= maxDepth(root->left);
        int righth= maxDepth(root->right);
        return 1+ max(lefth, righth);
    }
};

//approach 2: level order traversal
class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level= 0;
        while(!q.empty()) {
            int size= q.size();
            for(int i=0; i<size; i++) {
                TreeNode *node= q.front();
                q.pop();
                if(node->left)  q.push(node->left);
                if(node->right)  q.push(node->right);
            }
            level++;
        }
        return level;
    }
};
