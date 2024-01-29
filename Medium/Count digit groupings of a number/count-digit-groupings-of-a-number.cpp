//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int f(int sum,int i,string &s,vector<vector<int>> &dp){
        if(i==s.size()){
            return 1;
        }
        if(dp[sum][i]!=-1) return dp[sum][i];
        int ans=0;
        int curr_sum=0;
        for(int j=i;j<s.size();j++){
            curr_sum+=(s[j]-'0');
            if(curr_sum>=sum){
                ans+=f(curr_sum,j+1,s,dp);
            }
        }
       return dp[sum][i]=ans; 
    }
    int TotalCount(string str){
        // Code here
        vector<vector<int>> dp(1000,vector<int>(str.size(),-1));
        return f(0,0,str,dp);
    }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends