class Solution {
public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        sort(prices.begin(), prices.end());
        int n = prices.size();
        
        // Minimum cost
        int minCost = 0;
        int i = 0, j = n - 1;
        while (i <= j) {
            minCost += prices[i]; // Buy cheapest
            i++;
            j -= k; // Get k most expensive for free
        }
        
        // Maximum cost
        int maxCost = 0;
        i = n - 1, j = 0;
        while (j <= i) {
            maxCost += prices[i]; // Buy most expensive
            i--;
            j += k; // Get k cheapest for free
        }
        
        return {minCost, maxCost};
    }
};