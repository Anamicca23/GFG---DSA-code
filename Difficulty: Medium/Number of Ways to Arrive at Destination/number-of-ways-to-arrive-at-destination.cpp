class Solution {
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
        // code here
         vector<pair<int,int>> adj[V];
        priority_queue<pair<int,int>, 
                       vector<pair<int,int>> ,
                       greater<pair<int,int>>> pq;
                       
        vector<int> dist(V,INT_MAX), ways(V,0);
        
        for(int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
            
        }
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});
        
        while(pq.size())
        {
            int node = pq.top().second;
            int node_dist = pq.top().first;
            pq.pop();
            for(auto it: adj[node])
            {
                int adjNode = it.first;
                int adjDist = it.second;
                if(node_dist + adjDist < dist[adjNode])
                {
                    dist[adjNode] =  node_dist + adjDist;
                    ways[adjNode] =  ways[node];
                    pq.push({dist[adjNode],adjNode});
                }
                else if(node_dist + adjDist == dist[adjNode])
                {
                    ways[adjNode] +=  ways[node];    
                }
            }
        }
        return ways[V-1];
    }
};