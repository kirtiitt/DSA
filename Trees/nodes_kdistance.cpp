/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//find parents of each node first then from target node move in all possible directions i.e. left, right and parent and find the nodes at distance k
//TC: O(n+ n) for parent and traversal, SC: O(n+ n+ n) for parent, visited and traversal queue
class Solution {
    void findParents(TreeNode* root, unordered_map <TreeNode*, TreeNode*> &parent, TreeNode* target) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node= q.front();
            q.pop();
            if(node->left) {
                parent[node->left]= node;
                q.push(node->left);
            }
            if(node->right) {
                parent[node->right]= node;
                q.push(node->right);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map <TreeNode*, TreeNode*> parent;
        findParents(root, parent, target);
        unordered_map <TreeNode*, int> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]= 1;
        int count= 0;
        while(!q.empty()) {
            int size= q.size();
            if(count== k)  break;
            for(int i=0; i<size; i++) {
                TreeNode* node= q.front();
                q.pop();
                if(node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left]= 1;
                }
                if(node->right && !visited[node->right]) {
                    q.push(node->right);
                    visited[node->right]= 1;
                }
                if(parent[node] && !visited[parent[node]]) {
                    q.push(parent[node]);
                    visited[parent[node]]= 1;
                }
            }
            count++;
        }
        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};
