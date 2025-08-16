class Solution {
  public:
    static bool comp(string a, string b) {
         return a + b > b + a;
    }

    string findLargest(vector<int> &arr) {
        vector<string> nums;
        for (int i = 0; i < arr.size(); i++) {
            nums.push_back(to_string(arr[i]));
        }
        sort(nums.begin(), nums.end(), comp);
        if (nums[0] == "0") {
            return "0";
        }
        string ans = "";
        for (int i = 0; i < nums.size(); i++) {
            ans += nums[i];
        }
        return ans;
    }
};