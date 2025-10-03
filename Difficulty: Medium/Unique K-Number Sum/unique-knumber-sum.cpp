class Solution {
  public:
    vector<vector<int>> ans;
    
    void f(int n,int k,vector<int> v,int l){
        if(v.size()==k){
            if(n==0) ans.push_back(v);
            return;
        }
        
        for(int i=l+1;i<=9;i++) {
            v.push_back(i);
            f(n-i,k,v,i);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(int n, int k) {
        vector<int> v;
        f(n,k,v,0);
        return ans;
    }
};