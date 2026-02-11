class Solution {
  public:
    int getCost(vector<int>& heights, vector<int>& cost, int h){
        int cst = 0;
        for(int i = 0;i<heights.size();i++){
            cst += cost[i]*(abs(heights[i] - h));
        }
        return cst;
    }
    int minCost(vector<int>& heights, vector<int>& cost) {
        int l = 1, r = 1e4+1, mincost = 0;
        while(l<=r){
            int m = l+(r-l)/2;
            
            int prev = getCost(heights, cost, m-1);
            int curr = getCost(heights, cost, m);
            int next = getCost(heights, cost, m+1);
            
            if(prev>=curr and curr<=next){
                return curr;
            }
            if(prev>=curr and curr>=next){
                l = m+1;
            }
            else{
                r = m-1;
            }
        }
        return -1;
    }
};