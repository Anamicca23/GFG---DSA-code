class Solution {
  public:
     vector<int> findGreater(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans(n);
        unordered_map<int,int>mp;
        
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }
        stack<int>st;
        st.push(arr[n-1]);
        ans[n-1]=-1;
        
        for(int i=n-2; i>=0; i--){
            
            while(st.size()>0 && mp[arr[i]] >= mp[st.top()]){
                
            st.pop();
            
            }
           
            if(st.size() >0 ) ans[i]=st.top();
            else ans[i]=-1;
            
            st.push(arr[i]);
        }
        return ans;
    }
};
