/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

//TC: O(height)+ O(height)+ O(n)= O(n) (linear), SC: O(n)
class Solution {
public:
    bool isLeaf(Node *node) {
        if(node->left==NULL && node->right==NULL)  return true;
        return false;
    }

    void leftBoundary(Node *root, vector<int> &ans) {
        Node *node= root->left;
        while(node) {
            if(!isLeaf(node))  ans.push_back(node->data);
            if(node->left)  node= node->left;
            else  node= node->right;
        }
    }
    
    void leafNodes(Node *root, vector<int> &ans) {
        if(isLeaf(root)) {
            ans.push_back(root->data);
            return;
        }
        if(root->left)  leafNodes(root->left, ans);
        if(root->right)  leafNodes(root->right, ans);
    }
    
    void rightBoundary(Node *root, vector<int> &ans) {
        Node *node= root->right;
        stack<int> s;
        while(node) {
            if(!isLeaf(node))  s.push(node->data);
            if(node->right)  node= node->right;
            else node= node->left;
        }
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
    }
    
    vector <int> boundary(Node *root) {
        vector<int> ans;
        if(!root)  return ans;
        if(!isLeaf(root))
            ans.push_back(root->data);
        leftBoundary(root, ans);
        leafNodes(root, ans);
        rightBoundary(root, ans);
        return ans;
    }
};
