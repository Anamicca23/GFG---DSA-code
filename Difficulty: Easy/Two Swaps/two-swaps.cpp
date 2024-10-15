//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
        // code here.
        int n = arr.size();
        int cnt=0,i=0;
        while(i<n){
            if(arr[arr[i]-1]!=arr[i]){
                swap(arr[arr[i]-1],arr[i]);
                cnt++;
            }else{
                i++;
            }
        }
      if(cnt>2)return false;
      return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends