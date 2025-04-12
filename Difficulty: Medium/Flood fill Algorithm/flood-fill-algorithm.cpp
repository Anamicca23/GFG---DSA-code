//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, 
    int sr, int sc, int newColor) {
        // Code here
        int n=image.size();
        int m=image[0].size();
        
        int dr[4]={-1, 0, 1, 0};
        int dc[4]={0, 1, 0, -1};
        
        int orgColor=image[sr][sc];
        if (orgColor == newColor) return image;
        image[sr][sc]=newColor;
        
        queue<pair<int, int>>q;
        
        q.push({sr, sc});
        
        while(!q.empty()){
            auto &it=q.front();
            int r=it.first;
            int c=it.second;
            q.pop();
            
            for(int i=0; i<4; i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && 
                image[nr][nc]==orgColor){
                    q.push({nr, nc});
                    image[nr][nc]=newColor;
                }
            }
        }
        return image;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends