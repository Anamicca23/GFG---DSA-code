//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        map<char,int> mp;
        for(auto it:s) mp[it]++;
       

        vector<int> v;
        for(auto it:mp) v.push_back(it.second);
        sort(v.begin(),v.end());
       

        int n = v.size();
        int i = n-1;
       

        while(k){
            while(i-1 >=0 && v[i-1] == v[i]) i = i-1;
            k--;
            v[i] -= 1;
            while(i+1 < n && v[i] < v[i+1] ) i = i+1;
        }
       

        int sum =0;
        for(auto it:v) sum += it*it;
        return sum;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends