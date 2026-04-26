class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
         int i=0,j=0,k=0;
         vector<int> ans;
         while(i<a.size() && j<b.size()&& k<c.size()) {
             if(a[i] == b[j] && b[j] == c[k] && a[i] == c[k]) {
                 if(ans.empty() || ans.back() !=a[i]){
                    ans.push_back(a[i]);
                 }
                 i++;j++;k++;
                 continue;
             }
             if(a[i] <= b[j] && a[i] <= c[k]) i++;
             else if(b[j] <= a[i] && b[j] <= c[k]) j++;
             else if(c[k] <= a[i] && c[k] <= b[j]) k++;
         }
         return ans;
    }
};