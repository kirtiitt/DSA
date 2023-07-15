/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <string>

//TC: O(n) serialize+ O(n) push values in q+ O(n) deserialize
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "#";
        return to_string(root->val)+ ","+ serialize(root->left)+ ","+ serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string s;
        for(int i=0; i<data.size(); i++) {
            if(data[i]==',') {  //pushes number and # in the queue
                q.push(s);
                s= "";
            }
            else    s+= data[i];
        }
        if(s.size()!=0)    q.push(s);  //push last element
        return solve(q);
    }

    TreeNode* solve(queue<string> &q) {
        string s= q.front();
        q.pop();
        if(s=="#")  return NULL;
        TreeNode *root= new TreeNode(stoi(s));
        root->left= solve(q);
        root->right= solve(q);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
