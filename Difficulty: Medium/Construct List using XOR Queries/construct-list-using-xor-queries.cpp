class Solution {
  public:
    vector<int> constructList(vector<vector<int>> &queries) {
        // code here
        int n =queries.size();
        vector<int> ans;
        int x = 0;
        for(int i=n-1;i>=0;i--){
            if(queries[i][0] == 1){
                 x ^= queries[i][1];
              
            }else{
                 ans.push_back(queries[i][1]^x);
            }
        }
        ans.push_back(0^x);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
