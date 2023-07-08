//TC: O(n), SC: O(n)
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            auto it= q.front();
            q.pop();
            Node *node= it.first;
            int x= it.second;
            mp[x]= node->data;
            if(node->left)  q.push({node->left, x-1});
            if(node->right)  q.push({node->right, x+1});
        }
        for(auto i: mp)  ans.push_back(i.second);
        return ans;
    }
};
