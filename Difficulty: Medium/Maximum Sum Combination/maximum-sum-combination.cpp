class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        sort(a.rbegin(),a.rend());
        sort(b.rbegin(),b.rend());
        priority_queue<pair<int,pair<int,int>>>pq;
        set<pair<int,int>>visited;
        vector<int>ans;
        
        visited.insert({0,0});
        pq.push({a[0]+b[0],{0,0}});
        while(k-- && !pq.empty())
        {
            auto t=pq.top();
            pq.pop();
            ans.push_back(t.first);
            int i=t.second.first;
            int j=t.second.second;
            if(i+1<a.size()  && visited.find({i+1,j})==visited.end())
            {
                pq.push({a[i+1]+b[j],{i+1,j}});
                visited.insert({i+1,j});
            }
             if(j+1<b.size()  && visited.find({i,j+1})==visited.end())
            {
                pq.push({a[i]+b[j+1],{i,j+1}});
                visited.insert({i,j+1});
            }
        }
        return ans;
    }
};