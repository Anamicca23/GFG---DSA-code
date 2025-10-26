class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int, vector<int>, greater<int>>pq;
        int n = arr.size();
        for(int i=0; i<n; i++){
            pq.push(arr[i]);
        }
        int cost=0;
        while(pq.size()>1){
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            int cur=(first+second);
            cost += cur;
            pq.push(cur);
        }
        return cost;
    }
};