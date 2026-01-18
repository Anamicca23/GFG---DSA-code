class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        vector<int> res(arr.size(), -1);
        stack<int> st;
        map<int,int> mp;
        
        for(int i = 0;i<arr.size();i++)mp[arr[i]]++;
        for(int i = 0;i<arr.size();i++){
            if(st.empty())st.push(i);
            else{
                while(!st.empty()  and mp[arr[i]]>mp[arr[st.top()]]){
                    res[st.top()] = arr[i];
                    st.pop();
                }
                
                st.push(i);
            }
        }
        return res;
    }
};