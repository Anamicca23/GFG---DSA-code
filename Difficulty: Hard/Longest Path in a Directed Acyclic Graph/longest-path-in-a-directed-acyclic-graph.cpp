class Solution {
  public:
    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {
        // code here
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto & edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            adj[u].push_back({v, w});
        }
        vector<int> dist(V, INT_MIN);
        priority_queue<pair<int, int>> pq;
        pq.push({0, src});
        dist[src] = 0;
        while (!pq.empty()) {
            auto [w, u] = pq.top();
            pq.pop();
            for (auto & [v, d] : adj[u]) {
                int totalDistance = w + d;
                if (dist[v] < totalDistance) {
                    dist[v] = totalDistance;
                    pq.push({totalDistance, v});
                }
            }
        }
        return dist;
    }
};

