class Solution {
  public:
     int countValid(int n, vector<int>& arr) {
    bool zero = 0;
    for(auto it: arr){
        if(it==0)zero =1;
    }
     int total = 9*pow(10,n-1);
     int nott = pow(10-arr.size(),n);
     // if zero is present then it;s ok, but not then we need to exclude from 
     //nott expected  which start from 0. EX: 0984
     if(zero==0)
     {
         nott-= pow(10-arr.size(),n-1);
     }
     return total-nott;
    }
};
