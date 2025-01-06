//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        
        vector<int> ans;
        sort(arr.begin() , arr.end());
        int n = arr.size();
        int s = 0 ; int e = n-1;
        int diff=INT_MAX;
        while(s<e){
            int pairsum= arr[s]+arr[e];
            if(abs(pairsum-target)<diff){
                diff=min(abs(pairsum-target),diff);
                ans= {arr[s] , arr[e]};
            }
            if(pairsum<target)s++;
            else if(pairsum > target) e--;
            else if(pairsum==target) return ans;
        }
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
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends