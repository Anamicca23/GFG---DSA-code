class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        int n = arr.size();
        vector <int> ans;
        
        for(int i = 0; i < n; i++){
            int idx = abs(arr[i]) - 1;
            
            if(arr[idx] > 0){
                arr[idx] = -arr[idx];
            }
            else ans.push_back(abs(arr[i]));
        }
        
        return ans;
    }
};