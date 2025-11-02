class Solution {
  public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        return (V*(V-1)/2 - edges.size());
    }
};