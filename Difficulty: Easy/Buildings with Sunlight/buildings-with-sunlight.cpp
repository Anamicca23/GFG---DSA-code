class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        // code here
        int cnt =0;
        int maxe = arr[0];
        for(int i =0;i<arr.size();i++)
        {
            if(maxe<=arr[i]) cnt++;
            maxe = max(maxe, arr[i]);
        }
        return cnt;
    }
};