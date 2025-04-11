//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User Function Template
 class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<int>>adj[V];
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>,
        greater<pair<int, int>>>pq;
        pq.push({0, src});
        
        vector<int>dist(V, 1e9);
        dist[src]=0;
        
        while(!pq.empty()){
            auto &it=pq.top();
            int d=it.first;
            int node=it.second;
            pq.pop();
            
            for(auto &it:adj[node]){
                int adjN=it[0];
                int adjW=it[1];
                if(d+adjW<dist[adjN]){
                    dist[adjN]=d+adjW;
                    pq.push({dist[adjN], adjN});
                }
            }
        }
        return dist;
    
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            edges.push_back({v, u, w});
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(V, edges, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends