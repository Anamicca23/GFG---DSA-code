//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    bool isCyclic(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& e : edges) adj[e[0]].push_back(e[1]);
        vector<bool> vis(V), rec(V);
        for (int i = 0; i < V; ++i)
            if (!vis[i] && dfs(i, adj, vis, rec)) return true;
        return false;
    }

private:
    bool dfs(int u, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& rec) {
        vis[u] = rec[u] = true;
        for (int v : adj[u]) {
            if (!vis[v] && dfs(v, adj, vis, rec)) return true;
            if (rec[v]) return true;
        }
        rec[u] = false;
        return false;
    }
};




//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends