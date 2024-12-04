//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        // If lengths are different, they cannot be rotations
        if (s1.length() != s2.length()) {
            return false;
        }

        // Concatenate s1 with itself
        string concat = s1 + s1;

        // Check if s2 is a substring of the concatenated string using Z algorithm
        return zAlgorithm(concat, s2);
    }

private:
    // Function to implement the Z Algorithm
    bool zAlgorithm(const string &text, const string &pattern) {
        string combined = pattern + "$" + text;
        int n = combined.length();
        vector<int> Z(n, 0);

        // Construct Z array
        int L = 0, R = 0, K;
        for (int i = 1; i < n; ++i) {
            if (i > R) {
                L = R = i;
                while (R < n && combined[R] == combined[R - L]) R++;
                Z[i] = R - L;
                R--;
            } else {
                K = i - L;
                if (Z[K] < R - i + 1) {
                    Z[i] = Z[K];
                } else {
                    L = i;
                    while (R < n && combined[R] == combined[R - L]) R++;
                    Z[i] = R - L;
                    R--;
                }
            }
        }

        // Check if any Z value equals the length of the pattern
        for (int i = 0; i < n; ++i) {
            if (Z[i] == pattern.length()) {
                return true;
            }
        }

        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        Solution sol;
        int result = sol.areRotations(s1, s2);
        if (result) {
            cout << "true" << endl;

        } else {
            cout << "false" << endl;
        }
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends