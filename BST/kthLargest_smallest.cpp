//brute force: store the inorder traversal and then output (k-1)th or (n-k)th element
//code for kth largest
//TC: O(n), SC: O(n)
class Solution {
    public:
    void traverse(Node *root, int &n, vector<int> &ans) {
        if(!root)   return;
        traverse(root->left, n, ans);
        ans.push_back(root->data);
        n++;
        traverse(root->right, n, ans);
    }
    
    int kthLargest(Node *root, int K) {
        vector<int> ans;
        int n= 0;
        traverse(root, n, ans);
        return ans[n- K];
    }
};

//efficient: traverse till k and keep a pointer when traversing and return when count== k or (n-k)
//kth smallest
//TC: O(k), SC: O(k) space comp can be improved using Morris traversal
class Solution {
public:
    void solve(TreeNode *root, int k, int &count, int &ans) {
        if(!root)   return;
        solve(root->left, k, count, ans);
        if(++count ==k) {
            ans= root->val;
            return;
        }
        solve(root->right, k, count, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int count= 0, ans;
        solve(root, k, count, ans);
        return ans;
    }
};
