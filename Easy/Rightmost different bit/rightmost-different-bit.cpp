//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
        int res = m^n;  // xor operation stroing to res
        int count = 1;
        while(res>0)   //for getting binary bits
        {
            if(res%2 == 1)       //if bits=1 return count
            {
                return count;
            }
            res=res/2;          //else return -1
            count++;
        }
        return -1;
    }
    //tc:-O(max(log m, log n))
    //sc:O(1)
};

//{ Driver Code Starts.

// Driver Code
int main()
{   
    int t;
    cin>>t; //input number of testcases
    while(t--)
    {
         int m,n;
         cin>>m>>n; //input m and n
         Solution ob;
         cout << ob.posOfRightMostDiffBit(m, n)<<endl;
    }
    return 0;     
} 
// } Driver Code Ends