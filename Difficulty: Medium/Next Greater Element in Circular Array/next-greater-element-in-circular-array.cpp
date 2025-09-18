class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st; // stores indices

    // Traverse the array twice to simulate circular behavior
    for (int i = 0; i < 2 * n; i++) {
        int num = arr[i % n];

        // Check if this num is the NGE for elements in stack
        while (!st.empty() && arr[st.top()] < num) {
            result[st.top()] = num;
            st.pop();
        }

        // Only push index during first pass
        if (i < n) {
            st.push(i);
        }
    }
    return result;
    }
};