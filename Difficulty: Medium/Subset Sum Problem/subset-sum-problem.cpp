//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<bool> prev(target+1, 0), cur(target+1, 0);
        prev[0] = cur[0] =  true;
        prev[arr[0]] = true;
        
        for(int ind = 1; ind<n; ind++){
            for(int k = 1; k <= target; k++){
                bool notTake = prev[k];
                bool take = false;
                if(arr[ind] <= k){
                    take = prev[k - arr[ind]];
                }
                
                cur[k] = notTake || take;
            }
            prev = cur;
        }
        
        return prev[target];
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends