class Solution {
  public:
    int minProd(vector<int>& arr) {
        // code here
        int n = arr.size();
        int negcount = 0;
        int negmax = -11;
        int mini = 11;
        int ans = 1;
        for(int i=0;i<n;i++){
            if(arr[i]<0){
                negcount++;
                if(negmax<arr[i])negmax = arr[i];
            }
            if(mini>arr[i])mini = arr[i];
            if(arr[i])ans*=arr[i];
        }
        if(negcount==0)return mini;
        if(negcount%2)return ans;
        return ans/negmax;
    }
};
