//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
        // Your code here
        map<int,int>mp;
        int prefix_sum=0,curr_sum=0,ans=0;
        mp[0]=1;
        for(int i=0;i<arr.size();i++){
            curr_sum+=arr[i];
            prefix_sum=curr_sum-tar;
            if(mp[prefix_sum]>0)ans+=mp[prefix_sum];
            mp[curr_sum]++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int tar = stoi(ks);
        Solution obj;
        int res = obj.subArraySum(arr, tar);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends