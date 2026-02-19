class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        vector<bool> mp(high-low+1, false);
        for(int &i: arr){
            if(i>=low and i<=high){
                mp[i-low] = true;
            }
        }
        vector<int> missing;
        for(int i = 0;i<(high-low+1);i++){
            if(!mp[i]){
                missing.push_back(i+low);
            }
        }
        return missing;
    }
};