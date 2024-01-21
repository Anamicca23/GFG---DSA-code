//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int vertexCover(int n, vector<pair<int, int>> &edges) {
        // Initialize ans with a large value
        int ans = 18;

        // Iterate over all possible subsets of vertices (represented by bits)
        for (int bit = 0; bit < (1 << n); bit++) {
            // Initialize the number of uncovered edges
            int m = edges.size();

            // Iterate over each edge in the graph
            for (auto i : edges) {
                int x = i.first, y = i.second;
                x--, y--; // Adjust vertices to 0-based indexing

                // Check if either endpoint of the edge is in the current subset
                if ((bit & (1 << x)) | (bit & (1 << y))) {
                    m--; // If yes, decrement the number of uncovered edges
                } else {
                    break; // If neither endpoint is in the subset, break the loop
                }
            }

            // If all edges are covered by the subset, update the minimum vertex cover size
            if (m == 0) {
                ans = min(ans, __builtin_popcount(bit));
            }
        }

        return ans; // Return the minimum vertex cover size
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> edges;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            edges.push_back({a,b});
        }
        Solution s;
        cout<<s.vertexCover(n,edges)<<endl;
    }
    return 0;
}
// } Driver Code Ends