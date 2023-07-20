//adjancey matrix
//n is node/ vertex and m edges
//SC: O(n*n)
void createMatrix(int n, int m) {
    //indexing of node is 1 based, n for 0 based
    vector<vector<int>> adj_matrix(n+1, vector<int>(n+1, 0));
    //or int adj[n+1][n+1]
    int u, v;
    for(int i=0; i<m; i++) {
        cin>>u>>v;
        adj_matrix[u][v]= adj_matrix[v][u]= 1;
    }
}
//for weighted graph: instead of 1 write weight


//adjaceny list
//SC: O(2*E) for undirected, O(E) for directed
void createList(int n, int m) {
    vector<vector<int>> adj_list(n+1);
    int u, v;
    for(int i=0; i<m; i++) {
        cin>>u>>v;
        adj_matrix[u].push_back(v);
        adj_matrix[v].push_back(u);  //omit for directed
    }
}
//for weighted graph: vector<vector<pair<int, int>> adj_list where pair represents node and weight resp
