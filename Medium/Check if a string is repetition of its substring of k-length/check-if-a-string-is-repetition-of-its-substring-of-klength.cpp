//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int kSubstrConcat (int n, string s, int k)
	{
	    // Your Code Here
	    if(n%k!=0){
	        return 0;
	    }
	    unordered_map<string, int> mp;
	    int i=0; 
	    while(i<n){
	        mp[s.substr(i, k)]++;
	        if(mp.size()>2){
	            return false;
	        }
	        i+=k;
	    }
	    if(mp.size()==1){
	        return 1;
	    }
	    auto it = mp.begin();
	    int c1 = it->second;
	    it++;
	    int c2 = it->second;
	    return (c1==1 && c2>=1) || (c2==1 && c1>=1);
	}
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		int k; cin >> k;
        Solution  ob;
		cout << ob.kSubstrConcat (n, s, k) << endl;
	}
}
// } Driver Code Ends