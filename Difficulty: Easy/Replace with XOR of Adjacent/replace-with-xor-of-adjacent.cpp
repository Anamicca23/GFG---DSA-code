class Solution {
  public:
    void replaceElements(vector<int>& arr) {
        // code here
        if(arr.size() ==1)return;
        int fr = arr[0]^arr[1] , en = arr.back() ^ arr[arr.size()-2];
        int a  = 0, b = arr[0] , c = arr[1];
        
        for(int i = 1 ; i<arr.size()-1;  i++){
            a= b;
            b = c;
            c = arr[i+1];
            arr[i] = a^c;
        }
        arr[0] = fr;
        arr.back()= en;
        return;
    }
};

