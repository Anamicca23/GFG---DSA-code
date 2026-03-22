class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        int time=0,n=mat.size(),m=mat[0].size();
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==2)
                    q.push({{i,j},0});
            }
        }
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            time=it.second;
            // cout<<it.first.first<<" "<<it.first.second<<endl;
            if(it.first.first>0){ //(i-1,j)
                if(mat[it.first.first-1][it.first.second]==1)
                {
                    q.push({{it.first.first-1,it.first.second},it.second+1});
                    mat[it.first.first-1][it.first.second]=2;
                }
            }
            if(it.first.first<n-1){ //(i+1,j)
                if(mat[it.first.first+1][it.first.second]==1)
                {
                    q.push({{it.first.first+1,it.first.second},it.second+1});
                    mat[it.first.first+1][it.first.second]=2;
                }
            }
            if(it.first.second>0){ //(i,j-1)
                if(mat[it.first.first][it.first.second-1]==1)
                {
                    q.push({{it.first.first,it.first.second-1},it.second+1});
                    mat[it.first.first][it.first.second-1]=2;
                }
            }
            if(it.first.second<m-1){ //(i,j+1)
                if(mat[it.first.first][it.first.second+1]==1)
                {
                    q.push({{it.first.first,it.first.second+1},it.second+1});
                    mat[it.first.first][it.first.second+1]=2;
                }
            }
            
        }
        
        bool flag=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1) flag=false;
            }
        }
        
        return flag?time:-1;
    }
};