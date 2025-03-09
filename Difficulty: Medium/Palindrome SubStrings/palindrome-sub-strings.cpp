//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int expand(string& s, int idx) {
        int i = idx;
        int j = idx;
        int n = s.length();
        int res = 0;
        
        while(i >= 0 && j < n){
            if(s[i] == s[j]) i--, j++;
            else break;
        }
        
        res += (j - idx - 1);
        
        i = idx;
        j = idx + 1;
        
        while(i >= 0 && j < n){
            if(s[i] == s[j]) i--, j++;
            else break;
        }
        
        res += (j - idx - 1);
        
        return res;
    }
    int countPS(string &s) {
        int n = s.length();
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            ans += expand(s, i);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends