class Solution {
  public:
    int countStrings(string &s) {
        // code here
        vector<int> c(26,0);
        for(int i = 0;i<s.length();i++){
                c[s[i]-'a']++;
        }
        int n = s.size();
        bool flag = false;
        int ans =n*(n-1)/2;
        for(int i =0;i<26;i++){
            if(c[i]>1)flag = true;
                ans -= c[i]*(c[i]-1)/2;
            
        }
        return flag?ans+1:ans;
    }
};