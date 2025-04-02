//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    bool isvalid(int m, int n, int i, int j){
        if(i>=0 && i<m && j>=0 && j<n) return true;
        return false;
    }
  public:
    // Function to find minimum time required to rot all oranges.

int orangesRotting(vector<vector<int>>& mat) {        
        queue<pair<pair<int,int>,int>> q;
        int m=mat.size();
        int n=mat[0].size();
        int fresh=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==2) q.push({{i,j},0});
                else if(mat[i][j]==1) fresh++;
            }
        }
        vector<int> dim={-1,0,1,0,-1};
        int ans=0;
        while(!q.empty()){
            auto rotten=q.front();
            q.pop();
            int x=rotten.first.first;
            int y=rotten.first.second;
            int t=rotten.second;
            for(int i=0;i<dim.size()-1;i++){
                int newx=x+dim[i];
                int newy=y+dim[i+1];
                if(isvalid(m,n,newx,newy) && mat[newx][newy]==1){
                    mat[newx][newy]=2;
                    q.push({{newx,newy},t+1});
                    fresh--;
                }
            }
            ans=max(ans,t);
        }
        return (fresh==0)?ans:-1;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends