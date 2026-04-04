class Solution {
  public:
    int totalWays(vector<int>& arr, int target) {
        //  code here
         int sum = 0;
        for(auto &e : arr)sum += abs(e);
        if(abs(target) > sum)return 0;
        int sz = 2*sum + 1;
        vector<int> prev(sz, 0);
        prev[(arr[0] + sum)%(sz)]++; 
        prev[(-arr[0] + sum)%(sz)]++; 
        for(int i = 1; i < arr.size(); i++){
            vector<int> curr (sz, 0);
            for(int j = -sum; j <= sum; j++){
                int temp = 0;
                if(j - arr[i] >= -sum){
                    temp += prev[(j - arr[i] + sum)%sz];
                }
                if(j + arr[i] <= sum){
                    temp += prev[(j + arr[i] + sum)%sz];
                }
                curr[(j + sum)%sz] = temp;
            }
            prev = curr;
        }
        return prev[(target + sum)%sz];
    }
};