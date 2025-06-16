class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    
    int helpaterp(vector<vector<int>> hospital)
    {
        //code here
        int ans = 0;
        int r = hospital.size()-1;
        int c = hospital[0].size()-1;
        
        queue<pair<int,int>> q;
        for(int i=0;i<=r;i++){
            for(int j=0;j<=c;j++){
                if(hospital[i][j]==2)
                    q.push({i,j});
            }
            
        }
        
        while(!q.empty()){
            int n = q.size();
            while(n--){
                auto z = q.front();
                q.pop();
                
                int ii = z.first;
                int jj = z.second;
                
                for(int k=0;k<4;k++){
                    int ix = ii+dx[k];
                    int jy = jj+dy[k];
                    
                    if(ix<0 || jy<0 || ix>r || jy>c || hospital[ix][jy]!=1){
                        
                    }
                    else{
                        q.push({ix,jy});
                        hospital[ix][jy]=2;
                    }    
                }
                
            }
            
            if(!q.empty())
                ans++;
            
        }
        
        for(int i=0;i<=r;i++){
            for(int j=0;j<=c;j++){
                if(hospital[i][j]==1)
                    return -1;
            }
            
        }
        
        
        return ans;
        
    }
};