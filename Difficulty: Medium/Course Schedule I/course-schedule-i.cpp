class Solution {
  public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> indeg(n);
        vector<vector<int>> adj(n);
        for(int i = 0;i<pre.size();i++){
            int u = pre[i][1], v = pre[i][0];
            indeg[v]++;
            adj[u].push_back(v);
        }
        queue<int> q;
        for(int i = 0;i<n;i++){
            if(indeg[i] == 0)q.push(i);
        }
        while(!q.empty()){
            int node = q.front();q.pop();
            for(int &neigh: adj[node]){
                indeg[neigh]--;
                if(indeg[neigh] == 0){
                    q.push(neigh);
                }
            }
        }
        
        for(int i = 0;i<n;i++)if(indeg[i])return false;
        return true;
    }
};