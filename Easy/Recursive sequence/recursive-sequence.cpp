//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    // Time Complexity: O(n^2), where n is the input parameter
    //   - The outer loop iterates 'n' times.
    //   - The inner loop iterates up to 'i' times for each iteration of the outer loop.
    // Space Complexity: O(1)
    //   - The space used is constant regardless of the input size.
    long long sequence(int n) {
        // Initialize variables to keep track of count and result
        long long cnt = 1; // Initialize count to 1
        long long res = 0; // Initialize result to 0
        
        // Iterate from 0 to n - 1
        for (int i = 0; i < n; i++) {
            long long prod = 1; // Initialize product to 1
            
            // Calculate product of consecutive numbers
            // Iterate from 0 to i
            for (int j = 0; j <= i; j++) {
                prod = (prod * cnt) % 1000000007; // Multiply product by current count and take modulo
                cnt++; // Increment count
            }
            
            // Update result by adding product modulo 1000000007
            res = (res + prod) % 1000000007;
        }
        
        // Return the final result
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends