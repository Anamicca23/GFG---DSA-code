class Solution {
  public:
  int sizeMp(int *arr){
      int cnt = 0;
      for(int i = 0 ; i < 26 ; i++) if(arr[i] > 0) cnt++;
      return cnt;
  }
    int longestKSubstr(string &s, int k) {
        int mp[26] = {0};
        int start = 0,ans = -2;
        for(int end = 0 ; end < s.length() ; end++){
            mp[s[end] - 'a']++;
            int sz = sizeMp(mp);
            if(sz == k) ans = max(ans, end - start);
            if(sz > k) mp[s[start++] - 'a']--;
        }
        return ans + 1;
    }
};