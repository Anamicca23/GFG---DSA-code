class Solution {
  public:
    vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank) {
        // code here
        int n = rank.size(), m = l.size(), rnk = 1;
        unordered_map <int,int> mp;
        for(int i=0;i<m;i++){
            for(int j=l[i];j<=r[i];j++)
            {
                mp[rnk] = j; 
                rnk += 1;
            }
        }
        for(int i=0;i<n;i++){
            rank[i] = mp[rank[i]];
        }
        return rank;
    }
};