class DSU{
    public:
    vector<int>rank;
    vector<int>par;
    
    DSU(int n){
        rank.resize(n,0);
        par.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    
    int find(int x){
        if(par[x]==x) return x;
        return par[x]=find(par[x]);
    }
    
    void Union(int x, int y){
        
        int x_par=find(x);
        int y_par=find(y);
        
        if(x_par==y_par) return;
        
        if(rank[x_par] < rank[y_par]){
            
            par[x_par]=y_par;
            
        }else if(rank[x_par] > rank[y_par]){
            
            par[y_par]=x_par;
        }else{
            par[y_par]=x_par;
            rank[x_par]++;
        }
    }
};


class Solution {
  public:
    ///Method-01 Using kruskal algorithm
    int kruskal(vector<vector<int>>& edges, int n){
        
        sort(edges.begin(), edges.end());
        DSU dsu(n);
        
        int sum=0;
        for(auto &e : edges){
            
            int wt=e[0];
            int u=e[1];
            int v=e[2];
            
            if(dsu.find(u) != dsu.find(v)){
                dsu.Union(u,v);
                sum+=wt;
            }
        }
        
        return sum;
        
    }
    
    ///Method-02 Using Prim's algorithm
    typedef pair<int,int>p;
    int prim(vector<vector<p>>& adj, int n){
         
        priority_queue<p,vector<p>, greater<p>>pq;
        pq.push({0,0});
        vector<bool>inMST(n,false);
        int sum=0;
        
        while(!pq.empty()){
            
            auto[cost,u]=pq.top();
            pq.pop();
            
            if(inMST[u]) continue;
            
            inMST[u]=true;
            sum+=cost;
            
            for(auto &[v,wt] : adj[u]){
                
                if(!inMST[v]){
                    pq.push({wt,v});
                }
            }
        }
        return sum;
    }
    
    int minCost(vector<vector<int>>& houses) {
        // code here
        int n=houses.size();//no. of vertices
        vector<vector<int>>edges;
        vector<vector<p>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                
                int x1=houses[i][0];
                int y1=houses[i][1];
                int x2=houses[j][0];
                int y2=houses[j][1];
                
                int cost= abs(x1-x2) + abs(y1-y2);
                
                //create edge list
                edges.push_back({cost,i,j});
                //create graph
                adj[i].push_back({j,cost});
                adj[j].push_back({i,cost});
            }
        }
       // return kruskal(edges, n);
        return prim(adj,n);
    
    }
};