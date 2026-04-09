class Solution {
  public:
    virtual vector<int> intersection(vector<int>& a, vector<int>& b){
      vector<int> ans;
      int na=a.size(), nb=b.size();
      
      int i=0, j=0;
      while(i<na && j<nb){
        if(a[i]<b[j]) i++;
        else if(b[j]<a[i]) j++;
        else{
          if((ans.size()) > 0){
            if((ans.back()) != a[i]) ans.push_back(a[i]);  
          }else ans.push_back(a[i]);
          
          i++; j++;
        }
      }
      
      return ans;
    }
};