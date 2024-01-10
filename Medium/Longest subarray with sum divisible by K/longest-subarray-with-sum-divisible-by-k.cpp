//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
    {
        vector<long long int> pre(n,-1);
        vector<int> rem(k,-1);
        long long int sum = 0,ans = 0;
        for(int i=0;i<n;i++)
        {
            pre[i] = arr[i]%k;
            if(arr[i] < 0) pre[i] += k;
            sum += pre[i];
            pre[i] = sum;
            int val = pre[i]%k;
            if(val == 0)
            {
                ans = max(ans,(long long int)i+1);
                continue;
            }
            if(rem[val] != -1)
            {
                ans = max(ans,(long long int)(i - rem[val]));
            }
            else rem[val] = i;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends