class Solution {
  public:
    bool divby13(string &s) {
        // code here
        long long int rem= 0;
        for (int i=0; i< s.length(); i++){
            char ch= s[i];
            int num= ch-'0';
            rem= (rem*10 + num)%13;
            
        }
        if(rem%13==0){
            return 1;
            
        }
    
        else {
            return false;
        }
    }
};