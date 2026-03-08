class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        int maxVal = 0;
        for(int num : arr)
            maxVal = max(maxVal, num);
        vector<bool> freq(maxVal + 1, false);
        for(int num : arr)freq[num] = true;
        for(int a = 1; a <= maxVal; a++) {
            if(!freq[a]) continue;
            for(int b = a; b <= maxVal; b++) {
                if(!freq[b]) continue;
                int c2 = a*a + b*b;
                int c = sqrt(c2);
                if(c <= maxVal && c*c == c2 && freq[c])
                    return true;
            }
        }
        return false;
    }
};