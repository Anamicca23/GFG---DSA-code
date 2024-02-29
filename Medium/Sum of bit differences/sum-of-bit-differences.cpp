//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
     long long sumBitDifferences(int arr[], int n) {
        long ans=0;
        for(int i=31;i>=0;i--){
            long one=0,zero=0;
            for(int j=0;j<n;j++){
                int bit=1<<i;
                if((arr[j]&bit)>0)one++;
                else zero++;
            }
            ans+=(one*zero)*2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumBitDifferences(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends