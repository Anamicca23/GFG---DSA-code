//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<long long> factorialNumbers(long long n) {
        // Write Your Code here
       long long pro =  1 ;
       vector< long long > ans ;
       for( int i = 1 ; i <= n ; i++ )
       {
           pro = pro * i ;
           if( pro <= n )
           {
               ans.push_back(pro);
           }
           
           else break ;
       }
       
       return ans ;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        vector<long long> ans = ob.factorialNumbers(N);
        for (auto num : ans) {
            cout << num << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends