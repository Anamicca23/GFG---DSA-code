class Solution {
    public: 
    int countSubarrays(vector < int > & arr, int k) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i] & 1) {
                arr[i] = 1;
            }
            else {
                arr[i] = 0;
            }
        }
        int ans = 0;
        unordered_map < int, int > mp;
        mp[0] = 1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (mp.find(sum - k) != mp.end()) {
                ans += mp[sum - k];
            }
            mp[sum]++;
        }
        return ans;

    }
};