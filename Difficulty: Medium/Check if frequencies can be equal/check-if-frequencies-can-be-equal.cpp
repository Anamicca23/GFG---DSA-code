class Solution {
  public:
    bool sameFreq(string& s) {
        vector<int>v(26,0);
        for(auto &b: s){v[b-'a']++;}
        sort(v.begin(), v.end(), greater<>());
        set<int>st;
        for(auto &b: v){if(b>0){st.insert(b);}}
        if(st.size()>2){return false;}
        if(st.size()==1){return true;}
        if(*st.begin()==1){return true;}
        if(v[0]!=v[1]+1){return false;}
        return true; 
    }
};