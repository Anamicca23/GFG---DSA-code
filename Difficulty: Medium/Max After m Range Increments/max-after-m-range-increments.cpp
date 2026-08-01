class Solution {
  public:
    int findMax(int n, vector<int>& a, vector<int>& b, vector<int>& k) {
        // code here
        vector<long long>temp(n+1 , 0);
        for(int i = 0 ;i<a.size() ; i++){
            temp[a[i]]+=k[i];
            temp[b[i]+1]-= k[i];
        }
        long long ans = temp[0];
        for(int i = 1 ;i< n  ; i++){
            temp[i]+= temp[i-1];
            ans = max(ans , temp[i]);
        }
        return (int)ans;
    }
};