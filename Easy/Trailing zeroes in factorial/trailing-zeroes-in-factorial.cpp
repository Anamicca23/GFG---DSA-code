//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int trailingZeroes(int n)
    {
        // Write Your Code here
        //Number of 5 in n! = number of trailing 0 .
        //formula= number of 5 in n!.
        int countzeroes=0;
        //considering initial power of 5 is 1.
        for(int i=5;(n/i)>0;i=i*5)
        countzeroes+=n/i;
        
        return countzeroes;
    }
    //Time complexity:O(log n), worst case:-O(n).
    //space complexity:O(n).
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        int ans  = ob.trailingZeroes(N);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends