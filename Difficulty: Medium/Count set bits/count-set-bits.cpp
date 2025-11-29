class Solution {
  public:
    int countSetBits(int n) {
        int sum = 0;
        int f = 2;
        while((f/2)<=n){
            sum+=(n/f)*(f/2);
            int rem = n - (n/f)*f + 1;
            if(rem > f/2){
                sum += rem-f/2;
            }
            f*=2;
        }
        return sum;
    }
};