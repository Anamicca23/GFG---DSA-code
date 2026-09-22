class Solution {
  public:
    string findLongestWord(string &s, vector<string> &d) {
        // code here
        vector<vector<int>> vec(s.size());
        vector<int> next(26,-1);
        vec[s.size()-1]=next;
        map<char, int> mp;
        mp[s[s.size()-1]]=s.size()-1;
        for(int i=s.size()-2;i>=0;i--){
            next[s[i+1]-'a']=i+1;
            vec[i]=next;
            mp[s[i]]=i;

        }
        vector<string> ans;
        int maxi=0;
        for(int i=0;i<d.size();i++){

            if(mp.find(d[i][0])==mp.end()) continue;
            int s=mp[d[i][0]];
            int j=1;
            for(;j<d[i].size();j++){
                s=vec[s][d[i][j]-'a'];
                if(s==-1) break;
            }
            if(j==d[i].size()){
                ans.push_back(d[i]);
                maxi=max(maxi,(int)d[i].size());
            }
        }
        sort(ans.begin(),ans.end());
        for(auto it:ans){
            if((int)it.size()==maxi) return it;
        }
        return "";
    }
};