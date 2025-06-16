class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        int police = 0;
        int thief = 0;
        int count = 0;
        while(police < arr.size() && thief < arr.size()){
            if(arr[police] != 'P'){
                police++;
            }
            else if(arr[thief] != 'T'){
                thief++;
            }
            else{
                if(abs(police - thief) <= k){
                    count++;
                    police++;
                    thief++;
                }
                else{
                    if(thief < police){
                        thief++;
                    }
                    else{
                        police++;
                    }
                }
            }
        }
        return count;
    }
};

