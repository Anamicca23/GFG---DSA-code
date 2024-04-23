//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  const int MOD = 1000000007;
    void multiply(long long A[2][2], long long B[2][2], long long res[2][2]) {
        long long temp[2][2];
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                temp[i][j] = 0;
                for (int k = 0; k < 2; ++k) {
                    temp[i][j] = (temp[i][j] + (A[i][k] * B[k][j]) % MOD) % MOD;
                }
            }
        }
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                res[i][j] = temp[i][j];
            }
        }
    }
    void power(long long A[2][2], long long n, long long res[2][2]) {
        long long temp[2][2] = {{1, 0}, {0, 1}}; 
        while (n > 0) {
            if (n & 1) {
                multiply(temp, A, temp);
            }
            multiply(A, A, A);
            n >>= 1;
        }
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                res[i][j] = temp[i][j];
            }
        }
    }
     int firstElement(int n) {
        long long A[2][2] = {{1, 1}, {1, 0}};
        long long result[2][2];
        power(A, n, result);
        return result[1][0];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends