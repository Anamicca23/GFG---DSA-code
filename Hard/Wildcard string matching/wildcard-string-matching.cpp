//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    private:
    bool solve(string& pattern, string& wild, int i, int j) {
        // base case
        // if we cross the 0th index of both pattern and wild, means string matched
        if(i<0 and j<0)
            return true;
        // if we have left charachter in pattern but we there is no charachter is left in wild
        if(i >= 0 and j < 0)
            return false;
        // if we have left charachter in wild but there is no char in pattern to match
        // their is a possibility that left char are * and we can replace it with empty, so we return tur
        // other wise return false
        if(i < 0 and j >= 0) {
            for(int k=0; k<=j; k++){
                if(wild[k] != '*')
                    return false;
            }
            return true;
        }
        
        // match case
        // if both index i and j are matched to the same char
        if(pattern[i] == wild[j] || wild[j] == '?') {
            return solve(pattern, wild, i-1, j-1);
        }
        else if(wild[j] == '*') {
            return (solve(pattern, wild, i-1, j) || solve(pattern, wild, i, j-1));
        }
        else 
            return false;
    }

    public:
    bool match(string wild, string pattern)
    {
        // code here
        int i = pattern.length()-1;
        int j = wild.length()-1;
        
        return solve(pattern, wild, i, j);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends