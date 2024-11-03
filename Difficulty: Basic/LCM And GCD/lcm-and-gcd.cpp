//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int greatestcd(long long a, long long b){
      if(b==0)return a;
      return greatestcd(b,a%b);
  }
    vector<long long> lcmAndGcd(long long a, long long b) {
        // code here
        long long gcd = greatestcd(a,b);
        long long lcm = (a*b)/gcd;
        return {lcm,gcd};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A, B;

        cin >> A >> B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A, B);
        cout << ans[0] << " " << ans[1] << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends