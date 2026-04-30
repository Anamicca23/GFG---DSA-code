class Solution {
  public:
    bool isMaxHeap(vector<int> &arr) {
        // code here
        int n = arr.size();
        for(int i=0; i<n;i++){
            int ca = 2*i+1;
            int cb = 2*i+2;
            if(ca<n and arr[ca]>arr[i])return false;
            if(cb<n and arr[cb]>arr[i])return false;
        }
        return true;
    }
};
