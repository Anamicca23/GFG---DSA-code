//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void merges(vector<int>&arr, int l, int mid, int r){
        int n = arr.size();
        vector<int>ans;
        int left =l, right = mid +1;
        while(left<=mid and right<=r){
            if(arr[left]<=arr[right]){
                ans.push_back(arr[left]);
                left++;
            }else{
                ans.push_back(arr[right]);
                right++;
            }
        }
        while(left<=mid){
            ans.push_back(arr[left]);
            left++;
        }
        while(right<=r){
            ans.push_back(arr[right]);
            right++;
        }
        for(int i=l; i<=r;i++){
            arr[i]=ans[i-l];
        }
    } 
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if(l>=r)return;
        int mid = (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merges(arr,l,mid,r);
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
        Solution obj;
        obj.mergeSort(arr, 0, arr.size() - 1);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends