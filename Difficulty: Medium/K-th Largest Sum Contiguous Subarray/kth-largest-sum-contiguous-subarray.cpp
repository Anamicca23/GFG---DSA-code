//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        // code here
        //priority_queue<int,vector<int>,greater<int>>pq;
        int n = arr.size();
        vector<int>vec;
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum+=arr[j];
                vec.push_back(sum);
                /*if(pq.size()<k){
                    pq.push(sum);
                }
                else{
                    if(pq.top()<sum){
                        pq.pop();
                        pq.push(sum);
                    }
                }*/
            }
        }
        sort(vec.begin(),vec.end(),greater<int>());
        return vec[k-1];
        //return pq.top();
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
        int k = stoi(ks);
        Solution obj;
        int res = obj.kthLargest(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends