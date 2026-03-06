class Solution {
public:
    string minWindow(string &s, string &p) {
        vector<int> need(256, 0);
        for(char c : p) 
            need[c]++;

        int left = 0;
        int count = p.size();
        int minLen = INT_MAX;
        int start = 0;

        for(int right = 0; right < s.size(); right++) {
            if(need[s[right]] > 0)
                count--;

            need[s[right]]--;
            while(count == 0) {

                if(right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                need[s[left]]++;

                if(need[s[left]] > 0)
                    count++;

                left++;
            }
        }

        if(minLen == INT_MAX) 
            return "";

        return s.substr(start, minLen);
    }
};

