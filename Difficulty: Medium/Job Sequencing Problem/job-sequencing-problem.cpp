//{ Driver Code Starts
// Driver code
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<pair<int, int>> jobs(n);

        int maxDays = 0;
        for (int i = 0; i < n; i++) {
            jobs[i] = {profit[i], deadline[i]};
            maxDays = max(maxDays, deadline[i]);
        }

        sort(jobs.rbegin(), jobs.rend()); // Sort jobs in decreasing order of profit

        vector<int> parent(maxDays + 1);
        for (int i = 0; i <= maxDays; i++) parent[i] = i; // Initialize disjoint set

        // Disjoint Set Find Function with Path Compression
        function<int(int)> find = [&](int day) {
            if (parent[day] == day) return day;
            return parent[day] = find(parent[day]);
        };

        int jobCount = 0, maxProfit = 0;

        for (auto& job : jobs) {
            int p = job.first, d = job.second;

            int availableDay = find(d); // Find closest available day
            if (availableDay > 0) {
                parent[availableDay] = find(availableDay - 1); // Update parent (union)
                jobCount++;
                maxProfit += p;
            }
        }

        return {jobCount, maxProfit};
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> deadlines, profits;
        string temp;
        getline(cin, temp);
        int x;
        istringstream ss1(temp);
        while (ss1 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            profits.push_back(x);

        Solution obj;
        vector<int> ans = obj.jobSequencing(deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends