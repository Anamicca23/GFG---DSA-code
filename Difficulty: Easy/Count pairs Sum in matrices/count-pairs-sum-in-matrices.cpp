class Solution {
  public:
    bool isSum(vector<vector<int>> &mat2, int sum){
        int m= mat2.size();
        int n=mat2[0].size();
        int low=0, high=m*n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int r=mid/n;
            int c= mid%n;
            if(mat2[r][c]==sum){
                return true;
            }else if(mat2[r][c]>sum){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return false;
    }
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
        int count=0;
        int m= mat1.size();
        int n=mat1[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(isSum(mat2, x-mat1[i][j])){
                    count++;
                }
            }
        }
        return count;
        
    }
};