//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        int m=meetings.size();
        sort(meetings.begin(),meetings.end());
        vector<int>count(n,0);
        priority_queue<int,vector<int>,greater<int>>free;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>busy;
        for(int i=0;i<n;i++){
            free.push(i);
        }
        for(auto u:meetings){
            int start=u[0];
            int end=u[1];
            while(!busy.empty() && busy.top().first<=start){
                free.push(busy.top().second);
                busy.pop();
            }
            if(!free.empty()){
                int room=free.top();
                free.pop();
                count[room]++;
                busy.push({end,room});
            }
            else{
                int t=busy.top().first;
                int room_idx=busy.top().second;
                t+=(end-start);
                busy.pop();
                busy.push({t,room_idx});
                count[room_idx]++;
            }
        }
        int max_used=0;
        for(int i=0;i<n;i++){
            if(count[i]>count[max_used]){
                max_used=i;
            }
        }
        return max_used;
    }
};

//{ Driver Code Starts.

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> m;
        vector<vector<int>> meetings(m, vector<int>(2));
        for (int i = 0; i < m; i++) {
            cin >> meetings[i][0] >> meetings[i][1];
        }
        Solution ob;
        cout << ob.mostBooked(n, meetings) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends