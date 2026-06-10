class Solution {
public:
    int binarySearchable(vector<int> &arr) {
        const int size = arr.size();
        int ans = 0;
        for(int &target: arr) {
        int low = 0;
        int high = size-1;
        while(low <= high) {
            int mid = low + ((high - low) / 2);
            if(arr[mid] == target) {ans++;break;}
            else if(arr[mid] > target) {high = mid-1;
            }else {low = mid+1;}
            }
        }
        return ans;
    }
};
