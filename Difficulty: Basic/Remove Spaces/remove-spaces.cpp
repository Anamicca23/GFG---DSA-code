class Solution {
  public:
    string removeSpaces(string& s) {
        int b = 0, i = 0;
        while(i<s.size()){
            if(s[i] == ' '){
                i++;
            }
            else{
                swap(s[b], s[i]);
                b++;i++;
            }
        }
        while(s.back() == ' ')s.pop_back();
        return s;
    }
};