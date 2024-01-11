//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string S, int k) {
        // size of the number .
        int N = S.size() ;
        // the main idea that i need to make the first char small as possbile so I will take 
        // the min aval one for the first positions .
        stack<char>st ;
        for(int i = 0 ; i < N ; i ++){
            // if there is availble number min my current take it
            while(!st.empty() and k and st.top() > S[i]) st.pop() , k --;
            st.push(S[i]) ;
        }
        // if i delete all chars
        if(st.empty()) return "0" ;
        // i have the min but don't use all k so finish it .
        while(k--) st.pop() ;
        string ans ;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop() ;
        }
        reverse(begin(ans),end(ans)) ;
        int i = 0 ;
        // remove the leading zeros 
        while(ans[i] == '0') i ++;
        return (i == ans.size() ? "0" : ans.substr(i)) ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends