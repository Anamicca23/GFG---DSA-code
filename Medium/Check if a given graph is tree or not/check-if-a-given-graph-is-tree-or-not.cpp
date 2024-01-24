//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
   bool dfs(int i,vector<vector<int>>&adj,vector<int>&vis,int p){
        vis[i]=1;
        for(auto j:adj[i]){
            if(p==j) continue;
            if(vis[j]==1) return true;
            if(dfs(j,adj,vis,i)) return true;
        }
        return false;
    }
    int isTree(int v, int m, vector<vector<int>> &adj) {
        vector<int>vis(v,0);
        vector<vector<int>>mat(v);
        for(auto i:adj){
            mat[i[0]].push_back(i[1]);
            mat[i[1]].push_back(i[0]);
        }
        if(dfs(0,mat,vis,-1)) return false;
        for(auto i:vis) if(i==0) return false;
        return true;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends