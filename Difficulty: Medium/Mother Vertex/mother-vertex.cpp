class Solution {
  public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }
    int findMotherVertex(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        vector<int> visited(V, 0);
        int candidate = -1;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited);
                candidate = i;
            }
        }
        fill(visited.begin(), visited.end(), 0);
        dfs(candidate, adj, visited);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                return -1;
            }
        }
        return candidate;
    }
};
