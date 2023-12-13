//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int makeProductOne(int arr[], int N) {
        // code here
        int count_zero = 0;
        int step = 0;
        int mul = 1;
        for(int i = 0; i < N ; i++)
        {
            if(arr[i] > 0){step += (arr[i] - 1);mul *= 1;}
            else if(arr[i] < 0){step += (-1 - arr[i]); mul *= -1;}
            else {step++;count_zero++;}
        }
        
        return (mul == 1 || count_zero > 0)?step:step+2;
    }
    //Time Complexity :- O(N)
    //Space Complexity :- O(1)
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.makeProductOne(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends