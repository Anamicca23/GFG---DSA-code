//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
        
    int maxIndexDiff(int a[], int n) 
    { 
        vector<int>v;
        v.push_back(n-1);
        for(int i=n-2;i>=0;i--){
            if(a[i]>a[v.back()])v.push_back(i);
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            while( v.size()>0 && a[i]<=a[v.back()]){
                ans=max(ans,v.back()-i);
                v.pop_back();
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends