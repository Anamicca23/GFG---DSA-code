class Solution
{
public:
    int catchThieves(vector<char> &arr, int k)
    {
        queue<pair<char, int>> q;
        int ans = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            char curr = arr[i];
            // Cleaning of beyond k distance
            while (!q.empty() && i - q.front().second > k)
                q.pop();

            if (!q.empty() && q.front().first != curr)
            {
                ans++;
                q.pop();
            }
            else
            {
                q.push({curr, i});
            }
        }
        return ans;
    }
};