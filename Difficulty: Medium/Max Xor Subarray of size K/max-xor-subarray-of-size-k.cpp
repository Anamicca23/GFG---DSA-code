class Solution {
public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int n=arr.size();
        int maxXor, cur=0;
        for(int i=0; i<n; i++) {
            cur^=arr[i];
            if(i==k-1) {
                maxXor=cur;
            }
            if(i>=k) {
                cur^=arr[i-k];
                maxXor=max(maxXor,cur);
            }
        }
        return maxXor;
    }
};