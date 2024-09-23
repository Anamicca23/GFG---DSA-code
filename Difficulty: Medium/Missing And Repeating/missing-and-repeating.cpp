//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        vector<int> res(2,0); 
        int n = arr.size();
        int f[n+1];
        memset(f,0,sizeof(f));
        for ( auto i : arr ) f[i]++;
        for ( int i = 1; i<=n; i++ ){
            if ( f[i] == 2 ) res[0] = i;
            if ( f[i] == 0 ) res[1] = i;
        } 
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends