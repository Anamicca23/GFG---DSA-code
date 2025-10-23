class Solution {
  public:
    bool isPossible(vector<int>& arr, int k) {
    map<int, int> freq;
    for (int x : arr) {
        freq[x]++;
    }

    map<int, int> need;

    for (int num : arr) {
        if (freq[num] == 0) {
            continue;
        }

        if (need[num] > 0) {
            need[num]--;
            need[num + 1]++;
            freq[num]--;
        } else {
            bool possible_to_start = true;
            for (int i = 1; i < k; ++i) {
                if (freq[num + i] == 0) {
                    possible_to_start = false;
                    break;
                }
            }

            if (possible_to_start) {
                for (int i = 0; i < k; ++i) {
                    freq[num + i]--;
                }
                need[num + k]++;
            } else {
                return false;
            }
        }
    }

    return true;
    }

};