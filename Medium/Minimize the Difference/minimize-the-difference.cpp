//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
        vector<pair<int,int>>nums(n);
        nums[n-1]={arr[n-1],arr[n-1]};
        for(int i=n-2;i>=0;i--){
            nums[i]={max(nums[i+1].first,arr[i]),min(nums[i+1].second,arr[i])};
        }
        int maxi=0;
        int mini=1e9;
        int ans=1e9;
        for(int i=k;i<n;i++){
            ans = min(ans,max(maxi,nums[i].first)-min(mini,nums[i].second));
            maxi=max(maxi,arr[i-k]);
            mini=min(mini,arr[i-k]);
        }
        ans= min(ans,maxi-mini);
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.minimizeDifference(n, k, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends