class Solution {
    int n, m;
    void dfs(int u, vector<int> &vis, vector<vector<int>> &adj) {
        vis[u] = 1;
        
        for(int v : adj[u]) {
            if(!vis[v]) {
                dfs(v, vis, adj);
            }
        }
    }
  public:
    int maxRemove(vector<vector<int>>& stones) {
        // Code here
        n = stones.size();
        int ans = 0;
        int rows = 0, cols = 0;
        unordered_set<int> isVertex;
        
        for(int i = 0; i < n; i++) {
            rows = max(rows, stones[i][0]);
            cols = max(cols, stones[i][1]);
        }
        
        rows++;
        cols++;
      
        int V = rows + cols;
        vector<vector<int>> adj(V);
        
        for(int i = 0; i < n; i++) {
            adj[stones[i][0]].push_back(stones[i][1] + rows);
            adj[stones[i][1] + rows].push_back(stones[i][0]);
            isVertex.insert(stones[i][0]);
            isVertex.insert(stones[i][1] + rows);
        }
       
        vector<int> vis(V, 0);
        int components = 0;
        
        for(int i = 0; i < V; i++) {
            if(!vis[i] && isVertex.count(i)) {
                dfs(i, vis, adj);
                components++;
            }
        }
        return n - components;
    }
};