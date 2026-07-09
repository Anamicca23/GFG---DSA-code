class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        // code here
        int ans=0;
        vector<int>rem(k,0);
        for(int i=0;i<arr.size();i++){
            int reminder=arr[i]%k;
            if(reminder==0)
                ans+=rem[0];
            else
                ans+=rem[k-reminder];
            rem[reminder]++;
        }
        return ans;
    }
};

