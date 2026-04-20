class Solution {
public:
    vector<bool> bit;
    int tot;
    vector<unordered_map<int, int>> vec;

    int serialize() {
        int res = 0;
        for (auto it : bit)
            res = (res << 1) | it;
        return res;
    }
    
    int solve(int pos) {
        if (pos == tot)
            return 1;

        if (vec[pos].find(serialize()) != vec[pos].end())
            return vec[pos][serialize()];

        int res = 0;
        for (int i = 1; i <= tot; i++)
            if (i != pos + 1 && bit[i - 1] == false) {
                bit[i - 1] = true;
                res += solve(pos + 1);
                bit[i - 1] = false;
            }
        return vec[pos][serialize()] = res;
    }
    
    int derangeCount(int n) {
        bit = vector<bool>(n, false);
        tot = n;
        vec = vector<unordered_map<int, int>>(n);
        return solve(0);
    }
};