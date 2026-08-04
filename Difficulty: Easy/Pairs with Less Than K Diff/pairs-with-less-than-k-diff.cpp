class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int left = 0;
        int right = 0;
        int ans = 0;
        
        while(right<n){
            if(right==left)right++;
            else{
                int diff = abs(arr[right]-arr[left]);
                if(diff<k){
                    ans+=(right-left);
                    right++;
                }else left++;
            }
        }
        return ans;
    }
};
 