class Solution {
  public:
    vector<int> nextPalindrome(vector<int>& num) {
        int n = num.size();
        int idx = n/2 - (n%2 == 0);
        while(idx>=0){
            if(num[idx] > num[n-1-idx]){
                for(int i = 0;i<=n/2;i++){
                    num[n-1-i] = num[i];
                }
                return num;
            }
            else if(num[idx] < num[n-1-idx])break;
            idx--;
        }
        
        idx = n/2 - (n%2 == 0);
        int carry = 1;
        while(idx>=0){
            num[idx] = (num[idx]+carry)%10;
            num[n-1-idx] = num[idx];
            carry = (num[idx]%10 == 0);
            idx--;
        }
        if(num[0] == 0){
            num[0]= 1;
            num.push_back(1);
        }
        return num;
    }
};