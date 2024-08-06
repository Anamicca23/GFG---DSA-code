//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
   int isValid(string str) {
        
        if(str[0] == '0' or str[0] == '.')
        {
            return false;
        }
        int n = str.length();
        
        string temp = "";
        int cnt = 0,t1 = 0;
        for(int i=0;i<n;i++)
        {
            if(str[i] != '.')
            {
                temp+= str[i];
            }
            else if(str[i] == '.' and str[i+1] != '.')
            {
                int t = 0;
                
                t = stoi(temp);
                
                
                if(t<0 or t>255)
                {
                    return false;
                }
                cnt++;
                temp = "";
            }
            else
            {
                return false;
            }
        }


        if(temp.size()>0)
        {
            t1 = stoi(temp);
        }
        if(cnt == 3 and t1>=0 and t1<=255)
        {
            return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends