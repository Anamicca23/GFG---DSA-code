class Solution {
  public:
    bool canFormPalindrome(string &s) {
        // code here
        vector<int>cnt(26,0);
        for(char c:s)cnt[c-'a']++;
        int co=0;
        for(int i=0;i<26;++i)co+=(cnt[i]%2);
        return co<=1;
    }
};