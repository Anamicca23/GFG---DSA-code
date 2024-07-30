//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
   vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
    
    string getDir(int i) {
        switch(i) {
            case 0:
                return "R";
            case 1:
                return "D";
            case 2:
                return "L";
            case 3:
                return "U";
        }
        return "";
    }
    
    bool isSafe(int i, int j, vector<vector<int>> &mat) {
        if(i >= 0 && i < mat.size() && j >= 0 && j < mat[0].size() && mat[i][j])
            return true;
        return false;
    }
    
    void dfs(int i, int j, string path, vector<vector<int>> &mat, vector<string> &ans) {
        if(i == mat.size()-1 && j == mat.size()-1) {
            ans.push_back(path);
            return;
        }
        
        for(int k = 0; k < dir.size(); k++) {
            int p = i + dir[k].first;
            int q = j + dir[k].second;
            
            if(isSafe(p,q,mat)) {
                mat[i][j] = 0;
                dfs(p,q,path+getDir(k),mat,ans);
                mat[i][j] = 1;
            }
        }
        
    }
    
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<string> ans;
        
        if(mat[0][0] == 0 || mat[mat.size()-1][mat.size()-1] == 0)
            return ans;
            
        dfs(0,0,"",mat,ans);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends