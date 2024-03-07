//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    string longestSubstring(string s, int n) {
        int ind=0, mx=0;
        int low=1, high=n/2, mid;
        while(low<=high){
            mid=(low+high)>>1;
            int id=n+1;
            
            for(int i=0;i<=n-mid;++i){
                string sub=s.substr(i,mid);
                if(s.find(sub,i+mid)!=string::npos){
                    id=i;
                    break;
                }
            }
            
            if(id!=n+1){
                low=mid+1;
                if(mid>mx){
                    ind=id;
                    mx=mid;
                }
            }
            else  high=mid-1;
        }
        
        if(mx==0)  return "-1";
        return s.substr(ind,mx);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        string S;

        cin >> N;
        cin >> S;

        Solution ob;
        cout << ob.longestSubstring(S, N) << endl;
    }
    return 0;
}
// } Driver Code Ends