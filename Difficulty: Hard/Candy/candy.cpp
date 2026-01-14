class Solution {
public:
    int minCandy(vector<int>& ratings) {
       //one candy Toh obv needed
       vector<int> vec(ratings.size(), 1);
       vector<int> vec2(ratings.size(),1);
       for(int i=0; i<ratings.size(); i++){
        if(i-1>=0 && ratings[i]>ratings[i-1]){
            vec[i]= vec[i]+ vec[i-1];
        }
       } 
       for(int i= ratings.size()-1; i>=0; i--){
        if(i+1<ratings.size() && ratings[i]>ratings[i+1])
        vec2[i]= vec2[i]+vec2[i+1];
       }
       int ans=0;
       for(int i=0; i< ratings.size(); i++){
         ans += vec[i] > vec2[i] ? vec[i] : vec2[i];
        
       }

       return ans;

    }

};