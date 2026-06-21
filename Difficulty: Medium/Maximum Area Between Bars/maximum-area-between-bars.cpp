class Solution {
  public:
    int maxArea(vector<int> &height) {
        if(height.size()==1)
        return 0;
        int maxi=0;
        int i=0;
        int j=height.size()-1;
        while(i<j)
        {
            int val=min(height[i],height[j])*(j-i-1);
            maxi=max(maxi,val);
            if(height[i]<=height[j])
            i++;
            else
            j--;
        }
        return maxi;
    }
};
 