//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string s) {
        // code here
       int count=0;
       int n=s.size();
       unordered_map<char,int> dp;
       for(int i=0;i<n;i++){
           dp[s[i]]=i;
       }
       int minHit=-1;
       for(int i=0;i<n;i++){
           minHit = max(minHit,dp[s[i]]);
           if(minHit==i)
            count++;
       }
       return count;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends