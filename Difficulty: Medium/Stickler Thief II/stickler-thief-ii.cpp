//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int find(vector<int>&arr,int i,int n){
      int pre1=0,pre2=0;
      for(int j=i+1;j<=n;j++){
          int loot=arr[j-1];
          int dontloot=pre1;
          if(j>1)loot+=pre2;
          pre2=pre1;
          pre1=max(loot,dontloot);
      }
      return pre1;
  }
    int maxValue(vector<int>& arr) {
        // your code here
        int n=arr.size();
        int w1=find(arr,0,n-1);
        int w2=find(arr,1,n);
        return max(w1,w2);
    }
};





//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends