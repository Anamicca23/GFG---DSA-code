//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        const int INF=1e8;
        vector<int> dist(V,INF);
        dist[src]=0;
        bool flag;
        for (int i=0;i<V;i++){
            flag=true;
            for (auto it: edges){
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                if (dist[u]!=INF && dist[u]+wt<dist[v]){
                    flag=false;
                    dist[v]=dist[u]+wt;
                }
            }
            if (flag) return dist;
        }
        return {-1};
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int> > edges;

        for (int i = 0; i < E; ++i) {
            int u, v, w;
            cin >> u >> v >> w;

            vector<int> edge(3);
            edge[0] = u;
            edge[1] = v;
            edge[2] = w;
            edges.push_back(edge);
        }

        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.bellmanFord(V, edges, src);

        for (size_t i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends