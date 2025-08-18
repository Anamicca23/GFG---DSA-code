class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end()); // sort ascending
        int h = 0;
        
        for (int i = 0; i < n; i++) {
            int papersWithAtLeast = n - i;  // number of papers from i to n-1
            h = max(h, min(citations[i], papersWithAtLeast));
        }
        
        return h;
    }
};