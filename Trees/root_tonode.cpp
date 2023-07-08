/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//only one path possible
//TC: O(n), SC: O(n)
bool givePath(TreeNode *node, vector<int> &ans, int B) {
    if(node== NULL)  return false;
    ans.push_back(node->val);
    if(node->val== B)  return true;
    if(givePath(node->left, ans, B))  return true;
    if(givePath(node->right, ans, B))  return true;
    ans.pop_back();
    return false;
}

vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    givePath(A, ans, B);
    return ans;
}

//follow up problem: root to leaf
//multiple leaves so multiple paths need to be stored
//TC: O(n), SC: O(n)

/* Structure of Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};*/

void findpath(Node *root, vector<vector<int>> &ans, vector<int> &path) {
    if(!root)   return;
    path.push_back(root->data);
    if(!root->left && !root->right)
        ans.push_back(path);
    findpath(root->left, ans, path);
    findpath(root->right, ans, path);
    path.pop_back();
}

vector<vector<int>> Paths(Node* root) {
    vector<vector<int>> ans;
    vector<int> path;
    findpath(root, ans, path);
    return ans;
}
