//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
      vector<int> nthRowOfPascalTriangle(int n) {     
        int MOD=1e9+7;
        vector<int>temp;
        vector<int>v;
        if(n==1){
            v.push_back(1);
            return v;
        }
        temp=nthRowOfPascalTriangle(n-1);
        
        v.push_back(1);
        for(int i=0;i<temp.size()-1;i++){
            v.push_back((temp[i]+temp[i+1])%MOD);
        }
        
         v.push_back(1);
         return v;
    }
};



//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends