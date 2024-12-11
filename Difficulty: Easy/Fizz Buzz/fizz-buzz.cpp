//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    vector<string> fizzBuzz(int n) {
         vector<string> res;
         unordered_map<int, string> mp = 
                        {{3, "Fizz"}, {5, "Buzz"}};
         vector<int> divisors = {3, 5};
         for (int i = 1; i <= n; i++) {
         string s = "";

         for (int d : divisors) {
             if (i % d == 0)s.append(mp[d]);
        }
         if (s.empty())
            s.append(to_string(i));
         res.push_back(s);
    }

    return res;
 }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<string> res = obj.fizzBuzz(n);

        Array::print(res);
        cout << "~" << endl;
    }
}

// } Driver Code Ends