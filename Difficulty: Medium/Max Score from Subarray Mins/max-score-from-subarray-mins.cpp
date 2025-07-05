class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int ans = INT_MIN;
        for(int i = 1; i < arr.size(); i++)
        {
            ans = max(ans, arr[i] + arr[i-1]);
        }
        return ans;
    }
};