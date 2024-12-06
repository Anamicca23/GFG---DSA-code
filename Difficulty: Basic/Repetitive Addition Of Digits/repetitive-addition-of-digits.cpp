//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int singleDigit(int n) {
        while (n >= 10) { 
        int sum = 0;
        while (n > 0) {
            sum += n % 10; 
            n /= 10;       
        }
        n = sum; 
        }
    return n;
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
        int ans = ob.singleDigit(N);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends