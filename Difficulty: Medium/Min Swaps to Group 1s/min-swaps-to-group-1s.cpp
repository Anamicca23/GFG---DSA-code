class Solution {
public:
    int minSwaps(vector<int>& arr) {
        // code here
        int  n=arr.size();
        int k=0;
        for(int x:arr)if(x==1)k++;
        if(k==0)return -1;
        int curr_ones=0;
        for(int i=0;i<k;i++)if(arr[i]==1)curr_ones++;
        int max_ones=curr_ones;
        for(int i=k;i<n;i++){
            if(arr[i]==1)curr_ones++;
            if(arr[i-k]==1)curr_ones--;
            max_ones=max(max_ones,curr_ones);
        }
        return (k-max_ones);
    }
};