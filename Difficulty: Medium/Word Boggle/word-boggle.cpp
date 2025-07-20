class Solution {
  public:
    bool dfs(string &word, vector<vector<char>>& grid, int i, int j, vector<vector<int>>& vis, int idx) {
    if (idx == word.size()) return true;
    
    vis[i][j] = 1;
    int dx[8] = {0, 0, 1, -1, 1, -1, -1, 1};
    int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
    
    for (int k = 0; k < 8; k++) {
        int mrow = dx[k] + i;
        int mcol = dy[k] + j;
        
        if (mrow >= 0 && mcol >= 0 && mrow < grid.size() && mcol < grid[0].size() && 
            vis[mrow][mcol] == 0 && grid[mrow][mcol] == word[idx]) {
            if (dfs(word, grid, mrow, mcol, vis, idx + 1)) return true;
        }
    }
    
    vis[i][j] = 0;
    return false;
}
 
vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
    // Code here
    int n = board.size();
    int m = board[0].size();
    vector<string> ans;
    for(string word :dictionary)
    {   vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board[0].size() ; j++){
                if(board[i][j] == word[0]){
                    if(dfs(word,board,i , j ,vis,1)){
                        if(ans.size() == 0 || ans.back()!=word) ans.push_back(word);
                    }
                }
            }
        }
    }
    return ans;
}

};