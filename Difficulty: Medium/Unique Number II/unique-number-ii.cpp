//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    vector<int> singleNum(vector<int>& arr) {
        vector<int> res;
        for (int i = 0; i < arr.size() - 1; ++i)
            for (int j = i + 1; j < arr.size(); ++j)
                if ((arr[i] ^ arr[j]) == 0) {
                    arr[i] = arr[j] = 0;
                    break;
                }

        for (int x : arr)
            if (x) res.push_back(x);

        if (res[0] > res[1]) swap(res[0], res[1]);
        return res;
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

        Solution ob;
        vector<int> ans = ob.singleNum(arr);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends