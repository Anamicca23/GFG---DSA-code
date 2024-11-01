//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends

class Solution{
public:
    int evenlyDivides(int n){
        //code here
        int cnt=0,m=n,r=0;
        while(m!=0){
            r = m%10;
            if(r!=0 and n%r==0)cnt++;
            m/=10;
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;
    
cout << "~" << "\n";
}
    return 0; 
}
// } Driver Code Ends