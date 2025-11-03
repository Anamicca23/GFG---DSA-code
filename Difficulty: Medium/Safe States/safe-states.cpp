class Solution {
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(V, 0);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        
        vector<int> ans;
        queue<int> q;
        for (int i=0; i<V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            ans.push_back(u);
            q.pop();
            for (int v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        return ans;
    }
};