class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        int total = accumulate(begin(arr), end(arr), 0);
        
        int leftSum = 0;
        for (int v : arr) {
            leftSum += v;
            
            int rightSum = total - leftSum;
            
            if (rightSum == leftSum) {
                return true;
            }
        }
        
        return false;
    }
};