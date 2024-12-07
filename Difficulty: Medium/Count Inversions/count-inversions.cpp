//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to count inversions in the array.
     int count=0;
     void merge(vector<int>&arr, int l, int m, int r) {
      int j=m+1;
      for(int i=l;i<=m;i++){
          while(j<=r && arr[i]>arr[j]){
              j++;
          }
          count+=(j-(m+1));
      }
      sort(arr.begin()+l,arr.begin()+r+1);
    }
    
    void mergeSort(vector<int>&arr, int s,int  e){
        if(s>=e){
            return;
        }
        // cout<<"hi";
        int  mid=s+(e-s)/2;
      //  cout<<"hi";
        mergeSort(arr,s,mid);
        mergeSort(arr,mid+1,e);
        merge(arr,s,mid,e);
        
      }
    int inversionCount(vector<int>&arr)
    {
        
        int start=0;
        int end=arr.size()-1;
       mergeSort(arr,start,end); 
       return count;
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends