//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long countWays(int n, int k){
        // code here
          if(n==1)return k;
        long long same=k,diff=1LL*k*(k-1),total=same+diff,m=1e9+7;
        for(int i=3;i<=n;i++){
            same=diff;
            diff=total*(k-1)%m;
            total=(same+diff)%m;
        }
        return total;
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends