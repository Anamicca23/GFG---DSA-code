//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int addresser = 1;
    vector<vector<int>>criticalConnections(int v, vector<int> adj[]){
        // Code here
        vector<int> vis(v, 0);
        vector<int> address(v, -1);
        vector<int> alternateAdd(v, -1);
        vector<vector<int>> ans;
        
        dfs(0, -1, vis, address, alternateAdd, ans, adj);
        
        sort(ans.begin(), ans.end());
        return ans;
    }
    
    void dfs(int node, int parent, vector<int> &vis, vector<int> &address,
             vector<int> &alternateAdd, vector<vector<int>> &ans, vector<int> graph[]){
    
        vis[node] = 1;
        address[node] = alternateAdd[node] = addresser++;
        
        for(auto child: graph[node]){
            if(child == parent) continue;
            
            if(!vis[child]){
                dfs(child, node, vis, address, alternateAdd, ans, graph);
                alternateAdd[node] = min(alternateAdd[node], alternateAdd[child]);
                
                if(alternateAdd[child] > address[node]){
                    node < child? ans.push_back({node, child}) : ans.push_back({child, node});
                }
            }
            else{
                alternateAdd[node] = min(alternateAdd[node], alternateAdd[child]);
            }
        }
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends