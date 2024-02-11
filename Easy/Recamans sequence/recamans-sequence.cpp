//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> recamanSequence(int n){
        // The idea behind Recamán's sequence lies in alternately subtracting and adding integers to the previous term based on certain conditions.
        //This alternating behavior creates a sequence of distinct integers, each derived from the previous one by either subtraction or addition.
        //The challenge lies in ensuring that each term is distinct, which adds complexity to the generation process.
        //We can generate Recamán's sequence efficiently using a function. The function utilizes a set to keep track of visited numbers and a list to store the sequence.
        //By iterating through a range of numbers and applying the sequence generation rules, we can construct the desired sequence.
        unordered_map<int,int>hmap;
        hmap[0]++;
        vector<int>temp(n);
        temp[0]=0;
        for(int i=1;i<n;i++){
            int k=temp[i-1]-i;
            if(k>0 and hmap.find(k)==hmap.end()){
                temp[i]=k;
                hmap[k]++;
            }
            else{
                temp[i]=temp[i-1]+i;
                hmap[temp[i-1]+i]++;
            }
        }
        return temp;
    }
    /*Let's dry run the code for n = 5:

1. Initialize visited as {0, 1} and sequence as [0, 1].
2. Start iterating from i = 2 to 5.
3. At i = 2, current is 1. Since 1 - 2 = -1 is not positive, we add 2, yielding current = 3. Add 3 to visited and sequence.
4. At i = 3, current is 3. We subtract 3, yielding current = 0. Add 0 to visited and sequence.
5. At i = 4, current is 0. We add 4, yielding current = 4. Add 4 to visited and sequence.
6. At i = 5, current is 4. We subtract 5, yielding current = -1. Since -1 is not positive, we add 5, yielding current = 9. Add 9 to visited and sequence.

The resulting sequence is [0, 1, 3, 6, 2].
*/
//The time complexity of generating the Recamán sequence is O(n), where n is the number of elements required.
//The space complexity is also O(n) due to the storage of the sequence and visited numbers.

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends