//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
        string ans;
        int n = str.size();
        int m[84]={0};
       
        for(int i=0;i<n;i++){
            m[str[i]-'A']++;
        }
        for(int i=0;i<n;i++){
            if(m[str[i]-'A']!=0){
                ans+=str[i];
                m[str[i]-'A'] = 0;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends