class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& ma,
                                    vector<vector<int>>& opr) {
        // code here
        
        int n = ma.size(), m = ma[0].size();
        vector<vector<int>>mat(n,vector<int>(m,0));
        for(auto i : opr){
            int val= i[0] , r1 = i[1] , c1 = i[2] ,r2 = i[3] , c2 = i[4];
            mat[r1][c1]+=val;
            if(r2+1<n)mat[r2+1][c1]-=val;
            if(c2+1<m)mat[r1][c2+1]-=val;
            if(r2+1<n && c2+1<m)mat[r2+1][c2+1]+=val;
        }
        for(int i=1;i<m;i++)mat[0][i]+=mat[0][i-1];
        for(int i=1;i<n;i++)mat[i][0]+=mat[i-1][0];
        for(int i =1;i<n;i++){
            for(int j=1;j<m;j++){
                mat[i][j]+=mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)mat[i][j]+=ma[i][j];
        }
        return mat ;
    }
};