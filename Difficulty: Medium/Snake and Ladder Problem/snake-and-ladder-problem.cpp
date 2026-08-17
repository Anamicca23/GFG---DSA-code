class Solution {
public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int count[1000001] = {0};

        for(int i = 0;i<lad.size();i += 2){
            count[lad[i]] = lad[i+1];
        }
         for(int i = 0;i<sn.size();i += 2){
            count[sn[i]] = sn[i+1];
        }
        vector<int> dp((n*n)+1,INT_MAX);
        dp[1] = 0;
        pq.push({0,1});

        while(!pq.empty()){
            int a = pq.top().first;
            int b = pq.top().second;
            pq.pop();
            if(a > dp[b]){
                continue;
            }
            if(b == (n*n)){
                return a;
            }
            int c = -1;
            if(b % n == 0){
               c = (b/n) - 1;
            }
            if(b%n != 0){
                c = b/n;
            }
                for(int i = 1;i<=6;i++){
                    if(b+i <= (n*n)){
                       if(count[b+i] > 0){
                        if(dp[count[b+i]] > a+1){
                            dp[count[b+i]] = a+1;
                            pq.push({a+1,count[b+i]});
                        }
                       }
                       else{
                          if(dp[b+i] > a+1){
                            dp[b+i] = a+1;
                            pq.push({a+1,b+i});
                        }
                       }
                    }
                    else{
                        break;
                    }
                }
        }

        if(dp[n*n] == INT_MAX){
            return -1;
        }
        return dp[n*n];
    }
};

