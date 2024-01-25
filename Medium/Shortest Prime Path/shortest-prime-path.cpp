//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    bool isPrime(int n){
        for(int i = 2; i*i<=n; ++i){
            if(n % i == 0) return false;
        }
        return true;
    }
    int solve(int num1,int num2)
    {   
      //code here
      if(num1 == num2){
          return 0;
      }
      set<string> vis; // for stoping the repeating numbers. 
      queue<pair<int,int>> q; // for BFS, one for number and other for storing number of levels.
      q.push({num1,0});
      vis.insert(to_string(num1)); // to store inside the set. 
        while(!q.empty()){
            int num = q.front().first; // picking the elements, one by one from the queue.  
            int ans = q.front().second; // and for answer reference
            q.pop();
            if(num2 == num){return ans;} // this line is not required as it was more optimized afterwards.. 
            string s = to_string(num); // for better handling of code. O(1) operation. as 4 elements are only there. 
            for(int i = 0; i<4; ++i){ // iterating on each element 
                string sc = s;
                for(char ch = '0'; ch<='9'; ++ch){
                    if (i == 0 and ch == '0') continue; // this line is very important, stops from making it a 3 digit number. 
                    if(ch!=s[i]){
                        sc[i] = ch;
                        int chk = stoi(sc);
                        if(isPrime(chk) and vis.find(sc) == vis.end()){ // just check whether the number is prime and should not be present inside the visited set. 
                            if (num2 == chk) {
								return ans + 1; // this is the optimized version, as no need to push inside the queue.
							}
                            q.push({chk,ans+1});
                            vis.insert(sc);
                        }
                    }
                }
            }
        }
        
        return -1; // when no element found. 
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int num1,num2;
      cin>>num1>>num2;
      Solution obj;
      int answer=obj.solve(num1,num2);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends