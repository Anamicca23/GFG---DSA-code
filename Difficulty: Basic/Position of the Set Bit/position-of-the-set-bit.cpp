class Solution {
  public:
    int findPosition(int n) {
        // code here
        long long temp,count=0,p=-1,x=0,rem;
        temp=n;
        while(temp>0){
            x++;
            rem=temp%2;
            if(rem==1){
                count++;
            }
            if(rem==1 && p==-1){
                p=x;
            }
            temp=temp/2;
        }
        if(count>1){
            return -1;
        }
        return p;
    }
};