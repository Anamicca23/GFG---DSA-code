class Solution {
  public:
    int f(vector<int>&arr,int target)
    {
        int n = (int)arr.size();
        int i =0, j = 0,s = 0;
        int res = 0;
        while(j<n)
        {
            s+=arr[j];
            while(i<=j && s>target)
            {
                s-=arr[i];
                i++;
            }
            res += (j-i+1);
            j++;
        }
        return res;
    }
    int countSubarray(vector<int>& arr, int l, int r) {
        // code here
        int maxr = f(arr,r);
        int maxl = f(arr,l-1);
        return (maxr-maxl);
    }
};
