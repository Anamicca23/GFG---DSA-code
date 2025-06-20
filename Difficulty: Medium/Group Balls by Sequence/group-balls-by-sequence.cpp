class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        if(n%k!=0) return 0;
        set<int>s(begin(arr),end(arr));
        vector<int>nums(begin(s),end(s));
        for(int i=0;i<nums.size();i+=k){
            for(int j=i;j<i+k-1;j++){
                if(nums[j]+1!=nums[j+1]){
                    return 0;
                }
            }
        }
        return 1;
    }
};