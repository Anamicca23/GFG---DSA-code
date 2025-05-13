//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string s = countAndSay(n-1);
        int count = 0;
        char ch = s[0];
        string ans;
        for(int i=0;i<s.size();i++){
            if(s[i]!=ch){
                ans+=to_string(count);
                ans+=ch;
                count=1;
                ch = s[i];
            }
            else count++;
        }
        ans+=to_string(count);
        ans+=ch;
        return ans;
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
        cout << obj.countAndSay(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends