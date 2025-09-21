class Solution {
  public:
    void setNextSmallerFun(vector<int> &arr, vector<int> &nsi){
        stack<int> st;
        int n = arr.size();
        for(int i=n-1;i>=0;i--){
            while((!st.empty()) && (arr[i]<=arr[st.top()]))
              st.pop();
            if(st.empty())
              nsi[i] = n;
            else
              nsi[i] = st.top();
            
            st.push(i);  
        }
        return;
    }
    
    void setPrevSmallerFun(vector<int> &arr, vector<int> &psi){
        stack<int> st;
        int n = arr.size();
        for(int i=0;i<n;i++){
            while((!st.empty()) && (arr[i]<=arr[st.top()]))
              st.pop();
            if(st.empty())
              psi[i] = -1;
            else
              psi[i] = st.top();
            
            st.push(i);  
        }
        return;
    }
    
    
    
    vector<int> maxOfMins(vector<int>& arr) {
        //  code here
        int n = arr.size();
        vector<int> nsi(n, n), psi(n, -1);
        
        setNextSmallerFun(arr, nsi);
        setPrevSmallerFun(arr, psi);
        
        vector<int> ans(n, 0);
        
        for(int i=0;i<n;i++){
            int pos = nsi[i] - psi[i] - 1;
            ans[pos-1] = max(ans[pos-1], arr[i]);
        }
        
        for(int i=n-2;i>=0;i--){
            ans[i] = max(ans[i], ans[i+1]);
        }
        return ans;
    }
};

