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
    vector<vector<int>> kTop(vector<int>& arr, int n, int k) {
        vector<vector<int>> res;
        unordered_map<int, int> mp;
        set<pair<int, int>> s;
        
        for(auto i: arr) {
            vector<int> row;
            if(mp[i] > 0)
                s.erase({-mp[i], i});
                
            mp[i]++;
            s.insert({-mp[i], i});
            
            int t = 1;
            for(auto j: s) {
                if(t > k)
                    break;
                    
                row.push_back(j.second);
                t++;
            }
            
            res.push_back(row);
        }

        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> a(N);
        Array::input(a,N);
        
        Solution obj;
        vector<vector<int>> res = obj.kTop(a, N, K);
        
        for(auto it:res)
            Array::print(it);
        
    }
}

// } Driver Code Ends