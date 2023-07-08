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
    //use level order traversal and keep a flag for traversal direction
    //TC: O(n), SC: O(n)
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)  return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool LtoR= 1;
        while(!q.empty()) {
            int size= q.size();
            vector<int> level(size);
            for(int i=0; i<size; i++) {
                TreeNode *node= q.front();
                q.pop();
                if(node->left)  q.push(node->left);
                if(node->right)  q.push(node->right);
                //index for the vector
                int ind= (LtoR)? i: (size-i-1);
                level[ind]= node->val;
            }
            //change direction
            LtoR= !LtoR;
            ans.push_back(level);
        }
        return ans;
    }
};
