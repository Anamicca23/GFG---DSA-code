//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    
public:
    int findShortestPath(vector<vector<int>> &mat)
    {
       // code here
       int n = mat.size();
       int m = mat[0].size();
       
       queue<pair<int, int>> q; // {r, c}
       for(int i = 0; i < n; i++){
           for(int j = 0; j < m; j++){
               if(mat[i][j] == 0) q.push({i, j});
            }
        }
        
        int level = 0;
        
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        while(!q.empty()){
            
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                
                auto it = q.front();
                q.pop();
                
                int r = it.first;
                int c = it.second;
                
                mat[r][c] = 0;
                
                for(int j = 0; j < 4; j++){
                    int nr = r + drow[j];
                    int nc = c + dcol[j];
                    
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                        if(level == 0) q.push({nr, nc});
                    }
                }
                
            }
            
            level++;
            
        }
        
        
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++){
            if(mat[i][0] != 0) {
                q.push({i, 0});
                vis[i][0] = 1;
            }
        }
        
        level = 1;
        
        while(!q.empty()) {
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                auto it = q.front();
                q.pop();
                
                int r = it.first;
                int c = it.second;
                
                if(c == m - 1) return level;
                
                for(int j = 0; j < 4; j++){
                    int nr = r + drow[j];
                    int nc = c + dcol[j];
                    
                    //cout << n << " " << m << endl;
                    
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == 0 && mat[nr][nc] == 1){
                        //cout << "Explored " << "(" << nr << ", " << nc << ")" << endl;
                        q.push({nr, nc});
                        vis[nr][nc] = 1;
                    }
                }
            }
            
            level++;
        }
       
       
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends