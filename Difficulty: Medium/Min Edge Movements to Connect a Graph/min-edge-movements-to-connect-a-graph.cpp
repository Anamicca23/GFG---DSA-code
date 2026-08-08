class Solution {
  public:
    void DFS(int u, vector<vector<int>>& adj, vector<bool>& visited) 
    {
        visited[u]=true;
        for(int v:adj[u]) 
        {
            if(!visited[v]) 
            {
                DFS(v,adj,visited);
            }
        }
    }
    int minEdgesReq(int n, vector<vector<int>>& edges) {
        // code here
        if(edges.size()<n-1)    return -1;
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> dis(n,false);
        int g=0;
        for(int i=0;i<n;i++)
        {
            if(!dis[i])
            {
                dis[i]=true;
                g++;
                DFS(i,adj,dis);
            }
        }
        return g-1;
    }
};