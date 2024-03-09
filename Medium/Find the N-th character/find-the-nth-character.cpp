//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        //code here
        string newString(s);
        for(int i=0; i<r; i++){
            string temp;
            temp.reserve(newString.size() * 2);    
            for(int j=0;j<newString.size();j++){
                temp += (newString[j] == '1') ? "10" : "01";
                if(temp.size()>n){
                    break;
                }
            }
           newString = temp;
        }
        return newString[n];
    }
};
 

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends