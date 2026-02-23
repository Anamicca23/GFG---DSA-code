class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_set<int>st(a.begin(), a.end());
        st.insert(b.begin(), b.end());
        vector<int>ans(st.begin(), st.end());
        return ans;        
    }
};