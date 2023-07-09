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
    //width= no. of nodes in a level between 2 nodes 
    //indexing of every node and then using (first ind- last ind+ 1) to find the max width
    //bu the problem in this segment based indexing is of memory overflow, so what is done instead is that you subtract the min at each level so indexing becomes 0, 1, 2... at each level
    //earlier it was 0 at level 1 then 1, 2 at level 2 then 3, 4, 5, 6 at level 3 now it starts from 0 at each level
    //TC: O(n), SC: O(n)
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)  return 0;
        int ans= 0;
        queue <pair <TreeNode*, long>> q;
        q.push({root, 0});
        while(!q.empty()) {
            int size= q.size();
            long min= q.front().second;  //min is the first node at each level, duh
            long first, last;
            for(int i=0; i<size; i++) {
                long ind= q.front().second- min;
                TreeNode* node= q.front().first;
                q.pop();
                if(i== 0)  first= ind;
                if(i== size-1)  last= ind;
                if(node->left)  q.push({node->left, (long)ind*2+1});
                if(node->right)  q.push({node->right, (long)ind*2+2});
            }
            ans= max(ans, (int)(last-first+1));
        }
        return ans;
    }
};
