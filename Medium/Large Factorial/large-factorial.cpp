//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    vector<long long> factorial(vector<long long> arr, int n) {
    map<long long, long long>mp;
    mp[0] = 1;
    long long mx = *max_element(arr.begin(), arr.end());
    for (long long i = 0; i <=mx ; ++i)
        mp[i+1] = (i+1)*mp[i] % 1000000007;

    vector<long long> ans;
    for (int i = 0; i < n; ++i)
        ans.push_back(mp[arr[i]]);
    return ans;
}
//TC:-O(max(a)+n)
//SC:-O(n)
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<long long> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<long long> res = ob.factorial(a, n);
        for (i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends