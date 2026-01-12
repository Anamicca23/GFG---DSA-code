class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        map<int,int,greater<int>>mp;
        int i = 0,j = 0,n = arr.size();
        vector<int> ans;
        while(j<n)
        {
            mp[arr[j]]++;
            if(j-i+1 ==k)
            {    
                ans.push_back(mp.begin()->first);
                mp[arr[i]]--;
                if(mp[arr[i]] == 0)
                mp.erase(arr[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};

