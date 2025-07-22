class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        set<int> st;
        for (int i : arr){
            if (i > 0) st.insert(i);
        }
        for (int i = 1; i <= 1e6; i++){
            if (!st.count(i)) return i;
        }
    }
};