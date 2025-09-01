class Solution {
  public:
    int sumOfModes(vector<int>& arr, int k) {
        int n = arr.size();
        int x = 0, y = 0;  
        unordered_map<int,int> count;    // store frequency of numbers
        set<pair<int,int>> s;            // store {frequency, -value} (so higher freq comes later, and smaller value wins if tie)
        int ans = 0;

        while (y < n) {
            // put arr[y] into the window
            int num = arr[y];
            if (count[num] > 0) 
                s.erase({count[num], -num});  // remove old freq of num
            count[num]++;  
            s.insert({count[num], -num});     // add new freq of num

            // if window size becomes more than k, remove arr[x]
            if (y - x + 1 > k) {
                int left = arr[x];
                s.erase({count[left], -left});  
                count[left]--;  
                if (count[left] > 0) 
                    s.insert({count[left], -left});  
                x++;  // move left pointer
            }

            // if window size is exactly k, take the mode (highest freq number)
            if (y - x + 1 == k) {
                auto it = s.rbegin();   // last element = highest frequency
                ans += -it->second;     // add the number (not freq)
            }

            y++;  // expand window
        }

        return ans;
    }
};