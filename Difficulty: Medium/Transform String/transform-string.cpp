class Solution {
  public:
    int transform(string &s1, string &s2) {
        // code here
        if(s1.size()!=s2.size()) return -1;
        unordered_map<int,int> freq;
        for(char ch:s1) ++freq[ch];
        for(char ch:s2) --freq[ch];
        for(auto it:freq) {
            if(it.second) return -1;
        }
        int i=s1.size()-1, j=s2.size()-1;
        int ans=0;
        while(i>=0 && j>=0) {
            if(s1[i]==s2[j]) {
                i--; j--;
            } else {
                ans++;
                i--;
            }
        }
        return ans;
    }
};