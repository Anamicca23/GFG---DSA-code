//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User template code in C++

class Solution {
  public:
    bool sentencePalindrome(string &s) {
        // code here
        string s1 = "";
        for (char ch : s) {
            if (isalnum(ch)) {
                s1.push_back(tolower(ch));
            }
        }
    
        // find reverse of this new string
        string rev = s1;
        reverse(rev.begin(), rev.end());
    
        // compare string and its reverse
        return s1 == rev;
            
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        if (ob.sentencePalindrome(s))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}

// } Driver Code Ends