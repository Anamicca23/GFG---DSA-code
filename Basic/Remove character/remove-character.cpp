//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    string removeChars(string string1, string string2) {
        // code here
        map<char,int>mapie;
        for(int i=0; i<string2.length();i++)mapie[string2[i]]++;  //store all charecter and its freq of string2
        for(int i=0;i<string1.length();i++){
           if(mapie.find(string1[i])!=mapie.end()) //checks that char of string1 is present i map
           {
               string1.erase(string1.begin()+i);
               //if present it erase and adjust the index
               i--;
           }
        }
        return string1;  //return modified value of string1.
    }
    //time complexity:O(len(string1)+len(string2))
    //space complexity:O(26)/O(1)
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string string1,string2;
        cin >> string1; 
        cin >> string2;
        Solution ob;
        cout << ob.removeChars(string1,string2) << endl;
    }
    return 0;
}

// } Driver Code Ends