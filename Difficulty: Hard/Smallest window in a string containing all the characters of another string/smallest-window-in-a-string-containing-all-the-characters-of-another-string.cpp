//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
     string smallestWindow(string s, string p) {
        vector<int> mpp(26, 0);
        for (char ch : p) mpp[ch - 'a']++;

        int req = p.length(), i = 0, j = 0, n = s.length(), minSize = INT_MAX, sp = 0;

        if (req > n) return "-1";

        while (j < n) {
            if (mpp[s[j] - 'a'] > 0) req--;
            mpp[s[j] - 'a']--;

            while (req == 0) {
                if (j - i + 1 < minSize) {
                    minSize = j - i + 1;
                    sp = i;
                }
                mpp[s[i] - 'a']++;
                if (mpp[s[i] - 'a'] > 0) req++;
                i++;
            }
            j++;
        }

        return minSize == INT_MAX ? "-1" : s.substr(sp, minSize);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends