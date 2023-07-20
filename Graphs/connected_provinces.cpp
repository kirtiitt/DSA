//convert matrix into list, 0 based
void convert(vector<vector<int>> &isConnected) {
    vector<vector<int>> adj_list(n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) {
            if(isConnected[i][j] && i!=j) {  //avoid self loop
                adj_list[i].push_back(j);
                adj_list[j].push_back(i);
            }
            else if(isConnected[i][j] && i!=j)  //for self loop, write just once
                adj_list[i].push_back(j);
        }
}


//using DFS on matrix
//TC: O(V)+ O(V+2E) for outer and inner (dfs call) loop resp, SC: O(n+ n)
class Solution {
public:
    void dfs(int node, int n, vector<vector<int>> &isConnected, vector<int> &vis) {
        vis[node]= 1;
        for(int i=0; i<n; i++)
            if(isConnected[node][i] && !vis[i])
                dfs(i, n, isConnected, vis);
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected.size();
        vector<int> vis(n);
        int count= 0;
        for(int i=0; i<n; i++)
            if(!vis[i]) {
                count++;
                dfs(i, n, isConnected, vis);
            }
        return count;
    }
};

//using BFS on matrix
class Solution {
public:
    void bfs(int node, int n, vector<vector<int>> &isConnected, vector<int> &vis) {
        queue<int> q;
        q.push(node);
        vis[node]= 1;
        while(!q.empty()) {
            int temp= q.front();
            q.pop();
            for(int i=0; i<n; i++)
                if(!vis[i] && isConnected[temp][i]) {
                    vis[i]= 1;
                    q.push(i);
                }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected.size();
        vector<int> vis(n);
        int count= 0;
        for(int i=0; i<n; i++)
            if(!vis[i]) {
                count++;
                bfs(i, n, isConnected, vis);
            }
        return count;
    }
};
