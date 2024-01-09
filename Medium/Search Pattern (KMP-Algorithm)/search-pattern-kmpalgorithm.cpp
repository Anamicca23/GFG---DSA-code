//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    vector<int> prefix_function(string s) //KMP function
    {
        int n= s.length();
        vector<int> pi (n);
        
        for(int i=1; i<n; i++){
            int j= pi[i-1];
            
            while(j>0 && s[i] != s[j]){
                j = pi[j-1];
            }
            
            if(s[i]==s[j]){
                j++;
            }
            
            pi[i] = j;
        }
        return pi;
    }
    public:
        vector <int> search(string pat, string txt)
        {
            //code here
            string modified = pat + '?' + txt; // ? is the unallowed character in this string
            
            vector<int> kmp = prefix_function(modified);
            
            vector<int> res;
            
            int start = 2*pat.size();
            
            for(int i=start; i<modified.size(); i++){
                if(kmp[i] == pat.size()){
                    int idx = i-start+1; //1-based indexing
                    res.push_back(idx);
                }
            }
            
            return res;
        }

//Time complexity: O(n+m)
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends