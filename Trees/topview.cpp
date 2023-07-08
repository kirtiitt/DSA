/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
    public:
    //TC: O(n), SC: O(2n)= O(n)
    vector<int> topView(Node *root) {
        vector<int> ans;
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            auto it= q.front();
            q.pop();
            Node *node= it.first;
            int x= it.second;
            if(mp.find(x)== mp.end())  mp[x]= node->data;
            if(node->left)  q.push({node->left, x-1});
            if(node->right)  q.push({node->right, x+1});
        }
        for(auto i: mp)  ans.push_back(i.second);
        return ans;
    }
};
