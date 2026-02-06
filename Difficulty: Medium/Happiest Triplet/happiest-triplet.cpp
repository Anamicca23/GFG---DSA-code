class Solution {
public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        int n = a.size();
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());

        int i = 0, j = 0, k = 0;
        int mc = INT_MAX, ms = INT_MAX;
        vector<int> ans;

        while (i < n && j < n && k < n) {
            int mini = min({a[i], b[j], c[k]});
            int maxi = max({a[i], b[j], c[k]});
            int diff = maxi - mini;
            int sum = a[i] + b[j] + c[k];

            if (diff < mc || (diff == mc && sum < ms)) {
                mc = diff, ms = sum;
                ans = {a[i], b[j], c[k]};
            }

            if (mini == a[i]) i++;
            else if (mini == b[j]) j++;
            else k++;
        }

        sort(ans.begin(), ans.end(), greater<int>());
        return ans;
    }
};

