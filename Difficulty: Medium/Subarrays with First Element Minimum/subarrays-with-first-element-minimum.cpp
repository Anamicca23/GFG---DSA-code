class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        stack<int> st;
        int n = arr.size();
        int res = 0;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]>arr[i])
                st.pop();
            
            st.push(i);
            res += st.size();
        }
        return res;
    }
};