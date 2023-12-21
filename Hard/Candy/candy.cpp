//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minCandy(int N, vector<int> &ratings) {
        // code here
        if(N==0)return 0; //if there is no child then func return 0.
        vector<int>candies(N,1);  //taking array of candies and initially sets 1.
        //form left to right, if rating of current child is higher than previous one 
        //we increase their candies
        for(int i=0; i<N;i++){
            if(ratings[i]>ratings[i-1]){
                candies[i]=candies[i-1]+1;
            }
        }
        //from right to left, if ratings of current child is higher than next one
        //update their candies.
        for(int i=N-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                candies[i]=max(candies[i],candies[i+1]+1);
            }
        }
        //add up all candies they have then return it.
        int ans=0;
        for(int i=0;i<N;i++){
            ans+=candies[i];
        }
        return ans;
    }
    //time complexity:O(N)
    //space complexity:O(N)
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}
// } Driver Code Ends