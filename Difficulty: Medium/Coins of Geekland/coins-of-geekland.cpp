class Solution {

  public:
    int Maximum_Sum(vector<vector<int>> &mat,int n,int k){
        // Your code goes here
        int t=0;
        int p=k;
        vector<int> v;
        while(p<=n){
            int sm=0;
            for(int i=0;i<k;i++){
                for(int j=t;j<p;j++){
                    sm=sm+mat[i][j];
                }
            }
            v.push_back(sm);
            
            
            
            for(int i=k;i<n;i++){
                int sm1=0;
                int sm2=0;
                for(int j=t;j<p;j++){
                    sm1=sm1+mat[i-k][j];
                    sm2=sm2+mat[i][j];
                }
                sm=sm+sm2;
                sm=sm-sm1;
                v.push_back(sm);
            
                
            }
            p++;
            t++;
        }
        sort(v.begin(),v.end());
        return v[v.size()-1];
    }  


};