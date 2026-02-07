class Solution {
  public:
    int maxSum(vector<int> &arr) {
        deque<int>dq(arr.begin(),arr.end());
        int n= arr.size();
        int size = n;
        int initialSum = accumulate(arr.begin(),arr.end(),0);
        int ans = 0;
        int initialAns = 0;
        for(int i=0;i<arr.size();i++){
            initialAns+=i*arr[i];
        }
        ans = initialAns;
        while(dq.size()>0){
            int f = dq.front();
            int newAns = initialAns - initialSum + (f*size);
            ans = max(ans,newAns);
            initialAns = newAns;
            dq.pop_front();
        }
        return ans;
    }
};