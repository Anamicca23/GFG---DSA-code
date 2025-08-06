class Solution {
    public:
    int romanToDecimal(string &s) {
        // code here
        //slove the solution
        map<char, int> mp;
        mp['I']= 1;
        mp['V']=5;
        mp['X']=10;
        mp['L']= 50;
        mp['C']= 100;
        mp['D']=500;
        mp['M']=1000;
       int i=0;
       int ans=0;
       while(i<s.length()){
           if(i+1< s.length() and mp[s[i]]<mp[s[i+1]]){
               ans= ans+(mp[s[i+1]]- mp[s[i]]);
               i=i+2;
           }
           else{
               ans= ans+ mp[s[i]];
               i++;
           }
       }
       return ans;
    }
};