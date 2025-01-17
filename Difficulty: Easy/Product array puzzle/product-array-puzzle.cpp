//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
   vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> res(n, 0);
        
        int countZeros = 0;
        int zeroIndex = -1;
        long totalProd = 1;
        
        for(int i = 0; i < n; ++i){
            if(arr[i] == 0){
                countZeros += 1;
                zeroIndex = i;
            }else{
                totalProd *= arr[i];
            }
        }
        
        if(countZeros > 1) return res;
        
        if(countZeros == 1){
            res[zeroIndex] = totalProd;
            
            return res;
        }
        
        for(int i = 0; i < n; ++i){
            res[i] = totalProd / arr[i];
        }
        
        return res;
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

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends