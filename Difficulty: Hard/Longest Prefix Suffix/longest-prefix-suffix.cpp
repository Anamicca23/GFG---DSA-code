//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int lps(string str) {
        int n=str.length();
        vector<int>ans(n,0);
        int idx=0;
        
        for(int i=1;i<n;i++){
            
            if(str[i]==str[idx]){
                ans[i]=idx+1;
                idx++;
            }
            else{
                if(idx==0)
                    ans[i]=0;
                else{
                    idx=ans[idx-1];
                    i--;
                }    
            }
            
        }
        return ans[n-1];
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}

// } Driver Code Ends