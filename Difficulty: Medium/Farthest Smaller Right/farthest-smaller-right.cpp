class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        // code here
        priority_queue<pair<int,int>>pq;
        priority_queue<int,vector<int>,greater<int>>minstack;
        vector<int>ans;
        
        for(int i=arr.size()-1;i>=0;i--) {
           if(pq.empty()) {
               ans.push_back(-1);
               pq.push({i,arr[i]});
               minstack.push(arr[i]);
           } else {
               if(minstack.top()>=arr[i]) {
                   ans.push_back(-1);
                    pq.push({i,arr[i]});
                    minstack.push(arr[i]);
               } else {
                   vector<pair<int,int>>temp;
                   while(!pq.empty() && pq.top().second>=arr[i]) {
                       temp.push_back(pq.top());
                       pq.pop();
                   }
                   ans.push_back(pq.top().first);
                   for(int j=0;j<temp.size();j++) {
                       pq.push(temp[j]);
                   }
               }
           }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};