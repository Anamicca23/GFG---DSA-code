class Solution {
public:
    int countPaths(int V, vector<vector<int>>& edges) {
        
        vector<pair<int,int>> adj[V];
        for(auto &e : edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        vector<int> dist(V, 1e9);  
        vector<int> ways(V, 0);    

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while(!pq.empty()){
            auto it = pq.top(); pq.pop();
            int d = it.first;
            int node = it.second;

            for(auto &nbr : adj[node]){
                int next = nbr.first;
                int wt = nbr.second;

                if(d + wt < dist[next]){
                    dist[next] = d + wt;
                    ways[next] = ways[node];
                    pq.push({dist[next], next});
                }
                else if(d + wt == dist[next]){
                    ways[next] += ways[node];
                }
            }
        }

        return ways[V-1];
    }
};