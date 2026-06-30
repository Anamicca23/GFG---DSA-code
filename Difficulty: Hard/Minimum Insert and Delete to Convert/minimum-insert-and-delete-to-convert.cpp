class Solution {
public:
    int minInsAndDel(vector<int> &a, vector<int> &b) {
        vector<int> v;
        unordered_map<int,int> mp;
        for(int i = 0;i<b.size();i++){
            mp[b[i]]++;
        }
        for(int i = 0;i<a.size();i++){
            if(mp.find(a[i]) != mp.end()){
                v.push_back(a[i]);
            }
        }
        //finding LIS by B.S method.
        int cnt = 0;
        vector<int> w;
        w.push_back(v[0]);
        for(int i = 1;i<v.size();i++){
            if(v[i] > w[w.size()-1]){
                w.push_back(v[i]);
                continue;
            }
            int a = lower_bound(w.begin(),w.end(),v[i])-w.begin();
            w[a] = v[i];
        }
        return a.size()-w.size()+b.size()-w.size();
    }
};

