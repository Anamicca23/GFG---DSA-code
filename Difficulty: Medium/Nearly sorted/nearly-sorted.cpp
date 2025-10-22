class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        priority_queue<int, vector<int>,greater<int>> pq;
        int n = arr.size();
        int j = 0;
        
        for (int i=0; i <= k; i++) {
            pq.push(arr[i]);
        }
        
        for (int i = k+1; i < n; i++) {
            arr[j++] = pq.top();
            pq.pop();
            pq.push(arr[i]);
        }
        
        while (!pq.empty()) {
            arr[j++] = pq.top();
            pq.pop();
        }
    }
};