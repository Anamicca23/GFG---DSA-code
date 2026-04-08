class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int i=0;
        int j=arr.size()-1;
        int n=arr.size();
        while(i<=j){
            if(arr[i]==1 && arr[j]==0){
                swap(arr[i],arr[j]);
            }
            while(i<=j && arr[i]==0){
                i++;
            }
            while(j>=i && arr[j]==1){
                j--;
            }
            if(j<i){
                break;
            }
        }
    }
};