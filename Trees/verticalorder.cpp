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
    //can use any of the 4 traversals
    //TC: O(nlogn) (for traverse and multiset), SC: O(n)+ O(n) (for queue and map)
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>> > mp;
        queue<pair<TreeNode*, pair<int, int>> > q;
        q.push({root, {0,0}});
        while(!q.empty()) {
            auto ds= q.front();
            q.pop();
            TreeNode *node= ds.first;
            //x: vertice, y: level
            int x= ds.second.first, y= ds.second.second;
            mp[x][y].insert(node->val);
            if(node->left)  q.push({node->left, {x-1, y+1}});
            if(node->right)  q.push({node->right, {x+1, y+1}});
        }
        vector<vector<int>> ans;
        for(auto i: mp) {  //vertice
            vector<int> vertical;
            for(auto j: i.second)  //level
                vertical.insert(vertical.end(), j.second.begin(), j.second.end());
            ans.push_back(vertical);
        }
        return ans;
    }
};
