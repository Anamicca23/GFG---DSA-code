class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        sort(arr.begin(), arr.end());
        string num1 = "", num2 = "";
        int i = 0;
        while(i < arr.size())
        {
            if(i < arr.size())
            {
                num1 += '0' + arr[i];
                i++;
            }
            if(i < arr.size())
            {
                num2 += '0' + arr[i];
                i++;
            }
        }
        string sum = "";
        int i1 = num1.length() - 1, i2 = num2.length() - 1, carry = 0;
        while(i1 >= 0 || i2 >= 0 || carry > 0)
        {
            int n1 = 0, n2 = 0;
            if(i1 >= 0)
            {
                n1 = num1[i1] - '0';
                i1--;
            }
            if(i2 >= 0)
            {
                n2 = num2[i2] - '0';
                i2--;
            }
            int currSum = n1 + n2 + carry;
            carry = currSum / 10;
            int curr = currSum % 10;
            sum += '0' + curr;
        }
        reverse(sum.begin(), sum.end());
        int ind = 0;
        for(int i = 0; i < sum.length(); i++)
        {
            if(sum[i] != '0')
            {
                break;
            }
            ind++;
        }
        return sum.substr(ind);
    }
};