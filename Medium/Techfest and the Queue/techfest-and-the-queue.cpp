//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int PrimePowSum(int n){
        if(n==1)return 0;
        for(int i=2;(i*i)<n+1;i++){
            if(n%i==0)return (PrimePowSum(i)+PrimePowSum(n/i));
        }
        return 1;
    }
        
    
    int sumOfPowers(int a, int b){
        // Code here
        int ans=0;
        for (int i=a; i<=b;i++){
            ans+=PrimePowSum(i);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends