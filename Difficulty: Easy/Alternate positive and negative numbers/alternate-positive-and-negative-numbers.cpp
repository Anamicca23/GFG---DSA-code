//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    void rearrange(vector<int> &arr) {
        vector<int> pos,neg;
        for (int i=0;i<arr.size();i++)(arr[i] >= 0)?pos.push_back(arr[i]):neg.push_back(arr[i]);        int i=0,j=0;
        arr.clear();
        while (i < pos.size() && j < neg.size()) {
            arr.push_back(pos[i++]); 
            arr.push_back(neg[j++]); 
        }
        while (i < pos.size())arr.push_back(pos[i++]);
        while (j < neg.size())arr.push_back(neg[j++]);
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends