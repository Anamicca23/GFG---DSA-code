//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        // your code here
        unordered_map<int,int>mapie;//taking map to store frequency of each element
        for(int i=0; i<size;i++){
            mapie[a[i]]++;
        }
        for(auto & i:mapie){
        if(i.second>size/2)
           return i.first;
        }
        return -1;//If no majority element is found in the array, the function returns -1.
    }
    //time complexity:o(size)
    //space complexity:O(size)
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends

//------------------------------------------------------------------------------------------------------------------------
//2.approach

class Solution{
  public:
    int majorityElement(int a[], int size){
        int cnt=0,elm=-1;
         // Find a potential majority element
        for(int i=0;i<size;i++){
            if(cnt==0) elm=a[i];
            if(a[i]==elm) cnt++;
            else cnt--;
        }
        // now find the count of that element;
        cnt=0;
        for(int i=0;i<size;i++) {
            if(a[i]==elm) cnt++;
        }
        // Check if the candidate is the majority element condition
        if(cnt>floor(size/2)) return elm;
        return -1;
    }
    //tc:-O(size)
    //sc:-O(1)
};
