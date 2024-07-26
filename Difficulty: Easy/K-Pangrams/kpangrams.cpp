//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

   bool kPangram(string str, int k) {
        // code here
        int arr[26] = {0}, count=0, op=0;
        for(int i=0;i<str.length();i++){
            if(str[i] != ' '){
                arr[str[i]-'a']++;
                count++;
            }
        }
        
        for(int i=0;i<26;i++){
            if(arr[i] == 0){
                op++;
            }
        }
        
        return (k>=op) && (count >= 26);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends