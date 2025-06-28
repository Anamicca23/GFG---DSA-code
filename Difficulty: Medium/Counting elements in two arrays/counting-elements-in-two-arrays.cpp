class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        //maintain frequency array for b..
        int maxi1=*max_element(b.begin(),b.end());
        int maxi2=*max_element(a.begin(),a.end());
        int maxi=max(maxi1,maxi2);
        vector<int>freq(maxi+1,0);
        for(auto it:b)
        {
            freq[it]++;
        }
        //cumulative freq..
        for(int i=1;i<freq.size();i++)
        {
            freq[i]=freq[i]+freq[i-1];
        }
        vector<int>res(a.size());
        for(int i=0;i<a.size();i++)
        {
            res[i]=freq[a[i]];
        }
        return res;
    }
};