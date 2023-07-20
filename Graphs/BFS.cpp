class Solution {
  public:
    //TC: O(V+ 2*E), SC: O(2*V) for visited and queue
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfs;
        int visit[V]= {0};
        visit[0]= 1;
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int node= q.front();
            q.pop();
            bfs.push_back(node);
            for(auto i: adj[node])
                if(!visit[i]) {
                    visit[i]= 1;
                    q.push(i);
                }
        }
        return bfs;
    }
};
