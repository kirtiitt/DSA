//TC: O(n+ E), SC: O(n)
//instead of using vis and pathvis let vis have three values: 0 for not visited, 1 for visited, 2 for current path followed
class Solution {
  public:
    bool dfs(int node, vector<int> &vis, vector<int> adj[]) {
        vis[node]= 2;
        for(auto i: adj[node]) {
            if(!vis[i]) {
                if(dfs(i, vis, adj))   return true;
            }
            else if(vis[i]== 2)
                return true;
        }
        vis[node]= 1;
        return false;
    }
  
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        for(int i=0; i<V; i++)
            if(!vis[i])
                if(dfs(i, vis, adj))
                    return true;
        return false;
    }
};
