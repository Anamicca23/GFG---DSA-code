class Solution {
  public:
    int minMoves(vector<int>& arr) {
        // code here
        int N=arr.size();
        unordered_map<int, int> map;
        int maxi=0;
        for(int i=0;i<N;i++){
            map[arr[i]] = map[arr[i]-1]+1;
            maxi=max(maxi, map[arr[i]]);
        }
        return N-maxi;
    }
};