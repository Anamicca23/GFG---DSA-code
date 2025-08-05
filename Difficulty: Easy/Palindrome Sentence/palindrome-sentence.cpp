class Solution {
  public:
    bool isPalinSent(string &s) {
        // code here
      string cleaned = "";

        for (char c : s) {
          if (isalnum(c)) {
            cleaned += tolower(c);
          }
        }

        string reversed = cleaned;
        reverse(reversed.begin(), reversed.end());

      return cleaned == reversed;
    }
};