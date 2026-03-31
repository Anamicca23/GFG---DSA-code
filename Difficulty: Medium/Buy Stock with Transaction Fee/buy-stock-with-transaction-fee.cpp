class Solution {
  public:
    int maxProfitMemo(int index, bool buy, int &k, vector<int> &nums, vector<vector<int>> &dp) {
        if(index >= nums.size()) {
            return 0;
        }
        if(dp[index][buy] != -1) {
            return dp[index][buy];
        }
        int include = 0;
        if(buy) {
            include = nums[index] + maxProfitMemo(index+1, false, k, nums, dp);
        }
        else {
            include = -nums[index] -k + maxProfitMemo(index+1, true, k, nums, dp);
        }
        int exclude = maxProfitMemo(index+1, buy, k, nums, dp);
        return dp[index][buy] = max(include, exclude);
}

    int maxProfitTab(vector<int> &nums, int &k) {
        int size = nums.size();
        vector<vector<int>> dp(size+1, vector<int>(2, 0));
        
        for(int i = size-1; i >= 0; i--) {
            for(int buy = 0; buy <= 1; buy++) {
                int include = 0;
                if(buy == 1) {
                    include = nums[i] + dp[i+1][0];
                }
                else {
                    include = -nums[i] -k + dp[i+1][1];
                }
                int exclude = dp[i+1][buy];
                dp[i][buy] = max(include, exclude);
            }
        }
        return dp[0][0];
    }
    
    int maxProfitTabSO(vector<int> &nums, int &k) {
        int size = nums.size();
        vector<int> curr(2, 0);
        vector<int> next(2, 0);
        
        for(int i = size-1; i >= 0; i--) {
            for(int buy = 0; buy <= 1; buy++) {
                int include = 0;
                if(buy == 1) {
                    include = nums[i] + next[0];
                }
                else {
                    include = -nums[i] -k + next[1];
                }
                int exclude = next[buy];
                curr[buy] = max(include, exclude);
            }
            next = curr;
        }
        
        return curr[0];
    }
    
    int maxProfit(vector<int> &nums, int &k) {
        return maxProfitTabSO(nums, k);
    }
};