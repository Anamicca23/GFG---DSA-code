class Solution {
  public:
    void rearrange(vector<int> &arr, int x) {
        // code here
        map<int,vector<int>>mp;
        int n = arr.size();
        for(int i=0; i<n; i++){
            mp[abs(arr[i]-x)].push_back(arr[i]);
        }
        int i = 0;
        for(auto it : mp){
            for(auto itr : it.second){
                arr[i] = itr;
                i++;
            }
        }
    }
};