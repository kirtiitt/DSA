//using normal BFS traversal
//TC: O(n+ 2E), SC: O(2n)
class Solution {
public:
    bool colorG(int start, int n, vector<vector<int>> &graph, vector<int> &color) {
        queue<int> q;
        q.push(start);
        color[start]= 0;
        while(!q.empty()) {
            int node= q.front();
            q.pop();
            for(auto it: graph[node]) {
                if(color[it]== -1) {
                    color[it]= !color[node];
                    q.push(it);
                }
                else if(color[it]== color[node])    //it was colored earlier on some other path
                    return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int> color(n, -1);
        for(int i=0; i<n; i++)
            if(color[i]==-1)
                if(colorG(i, n, graph, color)== false)    return false;
        return true;
    }
};

//using normal DFS traversal
//TC: O(n+ 2E), SC: O(2n)
//graph not given- convert it into one
class Solution {
public:
    bool dfs(int node, int group, vector<vector<int>> &adj, vector<int> &color) {
        color[node]= group;
        for(auto it: adj[node]) {
            if(color[it]== -1) {
                if(dfs(it, !group, adj, color)== false)
                    return false;
            }
            else if(color[it]== group)
                return false;
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n+1, -1);
        vector<vector<int>> adj(n+1);
        for(auto i: dislikes) {
            //undirected graph adjacency list
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i=1; i<=n; i++)
            if(color[i]== -1)
                if(dfs(i, 0, adj, color)== false)   return false;
        return true;
    }
};
