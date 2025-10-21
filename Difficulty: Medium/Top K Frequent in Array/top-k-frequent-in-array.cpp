class Solution {
  public:
    static bool cmp(pair<int,int> a, pair<int,int> b){
        if(a.second == b.second){
            return a.first>=b.first;
        }
        return a.second>b.second;
    }
    vector<int> topKFreq(vector<int> &arr, int k) {
        int n = arr.size();
        map<int,int> mp;
        for(int i = 0;i<n;i++){
            mp[arr[i]]++;
        }
        vector<pair<int,int>> prr(mp.begin(), mp.end());
        sort(prr.begin(), prr.end(), cmp);
        
        vector<int> topk(k);
        for(int i = 0;i<k;i++){
            topk[i]=prr[i].first;
        }
        
        return topk;
    }
};