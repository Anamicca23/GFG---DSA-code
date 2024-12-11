//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
private:
    struct Trie {
        struct Node {
            Node* child[100];
            int cnt, last;
            vector<string> str;
            Node(): cnt(0), last(0), str(0) {
                for (int i = 0; i < 100; ++i) child[i] = NULL;
            }
        };
        
        Node* root;
        Trie() {
            root = new Node();
        }
        
        void insert(string s){
            Node* p = root;
            for (auto f : s){
                if (islower(f)) continue;
                int c = f - 'A';
                if (p->child[c] == NULL) p->child[c] = new Node();
                p = p->child[c];
                p->cnt++;
                p->str.push_back(s);
            }
            p->last++;
        }
        
        vector<string> find_answer(string pattern) {
            Node* p = root;
            for (auto f : pattern) {
                int c = f - 'A';
                if (p->child[c] == NULL) return {};
                p = p->child[c];
            }
            return p->str;
        }
    };    
    
public:
   vector<string> camelCase(vector<string> &arr, string &pat) {
        // code here
        Trie trie;
        for (auto s : arr) trie.insert(s);
        vector<string> ans = trie.find_answer(pat);
        if (ans.size() == 0) ans.push_back("[]");
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore(); // Clear the buffer after reading t
    while (t--) {
        string input;
        vector<string> arr;

        // Read the line of words
        getline(cin, input);
        stringstream ss(input);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        string pat;
        cin >> pat;
        cin.ignore(); // Clear the buffer after reading pat

        // Create an instance of the Solution class
        Solution ob;
        vector<string> ans = ob.camelCase(arr, pat);
        if (ans.empty()) {
            cout << "[]\n";
        } else {
            // Sort results before printing
            sort(ans.begin(), ans.end());
            for (const auto& u : ans)
                cout << u << " ";
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends