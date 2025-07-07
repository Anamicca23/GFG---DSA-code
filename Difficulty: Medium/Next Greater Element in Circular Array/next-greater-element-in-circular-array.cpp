class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        // code here
        int  n = arr.size();
        stack<int>st;
        vector<int>ans(n,-1);
        for(int i=0 ; i<n*2 ; i++){
            while(!st.empty() && arr[st.top()]<arr[i%n]){
                  ans[st.top()] = arr[i%n];
              st.pop();
          }
          if(i<n)
          st.push(i);
      }
      return ans;
            
    }
};