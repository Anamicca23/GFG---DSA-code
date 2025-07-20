class Solution {
  public:
    // Function to find most frequent word in an array of strings.
    string mostFrequentWord(string arr[], int n) 
    {
        int maxCount=0;
        string ans = "";
        unordered_map<string,int>mp;
        for(int i=n-1;i>=0;i--)
        {
            mp[arr[i]]++;
            if(mp[arr[i]]>maxCount)
            {
                maxCount=mp[arr[i]];
                ans = arr[i];
            }
        }
        return ans;
    }
};