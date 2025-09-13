class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        // Sort in descending order
        sort(x.rbegin(), x.rend());
        sort(y.rbegin(), y.rend());

        int i = 0, j = 0;
        int horizontal_segments = 1, vertical_segments = 1;
        int total_cost = 0;

        // Greedy selection
        while (i < x.size() && j < y.size()) {
            if (x[i] >= y[j]) {
                total_cost += x[i] * horizontal_segments;
                vertical_segments++;
                i++;
            } else {
                total_cost += y[j] * vertical_segments;
                horizontal_segments++;
                j++;
            }
        }

        // Remaining vertical cuts
        while (i < x.size()) {
            total_cost += x[i] * horizontal_segments;
            vertical_segments++;
            i++;
        }

        // Remaining horizontal cuts
        while (j < y.size()) {
            total_cost += y[j] * vertical_segments;
            horizontal_segments++;
            j++;
        }

        return total_cost;
    }
};