//using BFS
//TC: O(n)+ O(n +2E)= O(n+ 2E), SC: O(2n)= O(n)
class Solution {
  private:
    bool traverse(int startNode, int vis[], int V, vector<int> adj[]) {
        vis[startNode]= 1;
        queue<pair<int, int>> q;
        q.push({startNode, -1});
        while(!q.empty()) {
            int node= q.front().first, parent= q.front().second;
            q.pop();
            for(auto neighbour: adj[node]) {
                if(!vis[neighbour]) {
                    vis[neighbour]= 1;
                    q.push({neighbour, node});
                }
                else if (parent!= neighbour)
                    return true;  //different paths for the same node
            }
        }
        return false;
    }
  
  public:
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V]= {0};
        for(int i=0; i<V; i++)
            if(!vis[i])
                if(traverse(i, vis, V, adj))   return true;
        return false;
    }
};

//using DFS
//TC: O(n)+ O(n +2E), SC: O(2n)
class Solution {
  private:
    bool traverseDFS(int node, int parent, int vis[], int V, vector<int> adj[]) {
        vis[node]= 1;
        for(auto neighbour: adj[node]) {
            if(!vis[neighbour]) {
                if(traverseDFS(neighbour, node, vis, V, adj))   return true;
            }
            else if(neighbour!=parent)
                return true;
        }
        return false;
    }
  
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V]= {0};
        for(int i=0; i<V; i++)
            if(!vis[i])
                if(traverseDFS(i, -1, vis, V, adj))   return true;
        return false;
    }
};
