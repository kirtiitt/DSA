//TC: O(V+ 2*E), SC: O(2*V) for visited and recursion stack space
class Solution {
  private:
    void findDFS(int node, vector<int> adj[], int vis[], vector<int> &dfs) {
        vis[node]= 1;
        dfs.push_back(node);
        for(auto i: adj[node])
            if(!vis[i])
                findDFS(i, adj, vis, dfs);
    }
  public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V]= {0};
        vector<int> dfs;
        findDFS(0, adj, vis, dfs);
        return dfs;
    }
};

//did you know that you can implement this recursive dfs using stack easily, yes you can look into it
//possible because dfs explores a path as far as possible before backtracking
