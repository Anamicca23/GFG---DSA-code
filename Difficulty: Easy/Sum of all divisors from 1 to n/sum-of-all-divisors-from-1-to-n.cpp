//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long sumOfDivisors(int n) {
        // Write Your Code here
        long long sum=0;
        for(int i =1; i<=n; i++)sum+=(n/i)*i;
        return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        long long ans = ob.sumOfDivisors(N);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends