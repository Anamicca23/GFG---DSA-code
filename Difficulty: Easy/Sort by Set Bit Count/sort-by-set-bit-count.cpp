class Solution {
  public:
    vector<int> sortBySetBitCount(vector<int>& arr) {
        vector<vector<int>> buckets(32);

        for (int num : arr) {
            buckets[__builtin_popcount((unsigned int)num)].push_back(num);
        }

        vector<int> ans;
        ans.reserve(arr.size());
        for (int bits = 31; bits >= 0; --bits) {
            for (int num : buckets[bits]) {
                ans.push_back(num);
            }
        }

        return ans;
    }
}; 
