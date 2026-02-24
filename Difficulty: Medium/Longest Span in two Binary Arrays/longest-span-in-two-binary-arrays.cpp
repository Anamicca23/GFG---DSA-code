class Solution {
public:
    int equalSumSpan(vector<int>& a1, vector<int>& a2) {
        unordered_map<int, int> mp{{0, -1}};
        int n = a1.size(), sum = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            sum += a1[i] - a2[i];
            auto it = mp.find(sum);
            if (it != mp.end()) ans = max(ans, i - it->second);
            else mp[sum] = i;
        }
        
        return ans;
    }
};