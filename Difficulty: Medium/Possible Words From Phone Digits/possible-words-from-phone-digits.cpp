class Solution {
  public:
    void solve(int i, int n, vector<int>&arr, string temp, vector<string>&ans, vector<string>keys) {
        //base case
        if(i==n) {
            ans.push_back(temp);
            return;
        }
        
         // if digit is 0 or 1 (no mapping), just skip
        if (keys[arr[i]].empty()) {
            solve(i + 1, n, arr, temp, ans, keys);
            return;
        }
        
        for(int j=0; j<keys[arr[i]].size(); j++) {
            solve(i+1, n, arr, temp+keys[arr[i]][j], ans, keys);
        }
    }
    
    vector<string> possibleWords(vector<int> &arr) {
        // code here
        vector<string>keys = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string>ans;
        solve(0, arr.size(), arr, "", ans, keys);
        return ans;
    }
};