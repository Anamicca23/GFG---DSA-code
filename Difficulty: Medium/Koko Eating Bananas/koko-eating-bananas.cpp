class Solution {
public:
    int kokoEat(vector<int>& arr, int k) {
        int n = arr.size();
        int left = 1, right = *max_element(arr.begin(), arr.end());
        int result = right;

        while (left <= right) {
            int mid = (left + right) / 2;
            int totalHours = 0;

            for (int i = 0; i < n; i++) {
                // Correct way to compute hours to eat each pile
                totalHours += (arr[i] + mid - 1) / mid; // equivalent to ceil(arr[i] / mid)
            }

            if (totalHours <= k) {
                result = mid;          // possible answer, but try to minimize
                right = mid - 1;
            } else {
                left = mid + 1;        // too slow, need to eat faster
            }
        }

        return result;
    }
}; 