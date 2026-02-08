class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        int n = arr.size() , ans = INT_MIN;
        int pref = 1 , suff = 1;
        for(int i = 0; i < n; i++){
            pref *= arr[i];
            suff *= arr[n - i - 1];
            ans = max({ans , pref , suff});
            if(pref == 0)
                pref = 1;
            if(suff == 0)
                suff = 1;
        }
        return ans;
    }
};

