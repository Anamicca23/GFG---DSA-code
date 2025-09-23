class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        int n=q.size();
        vector<int>v(n);
        int j=n-1;
       while(!q.empty()){v[j--]=q.front();q.pop();}
       for(auto &i :v){q.push(i);}
    }
};