//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
  const int MOD=1e9+7;
   vector<int> Series(int n) {
        // Code here
         vector<int>fib(n+ 1);
          if(n>=0) {
            fib[0]=0;
        }
          if (n >= 1) {
            fib[1] = 1;
        }
    for(int i=2;i<=n;++i) {
        fib[i]=(fib[i-1]+fib[i-2])%MOD;
    }
    return fib;
   }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends