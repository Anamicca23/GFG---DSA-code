//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isPossible(vector<int> &stalls,int n, int c,int mid){
        int cows=1, lastStallPos = stalls[0];
        for(int i=1;i<n;i++)  {
            if((stalls[i]-lastStallPos) >= mid){
                cows++;
                lastStallPos=stalls[i];
            }
            
            if (cows==c){
                return true;
            }
        }
        
        return false;
    }
    
    int aggressiveCows(vector<int> &stalls, int c) {
        int n = stalls.size();
        int ans=-1;
        sort(stalls.begin(),stalls.end());
        int st=0,end=stalls[n-1]-stalls[0];
        while(st<=end){
            int mid= st + (end-st)/2;
            if(isPossible(stalls,n,c,mid)){
                ans=mid;
                st=mid+1;
            }
            else {
                end=mid-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends