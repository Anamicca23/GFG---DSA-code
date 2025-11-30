class TrieNode{
    public:
      bool isend;
      TrieNode* child[26];
    
      TrieNode(){
          isend=false;
          for(int i=0; i<26; i++){
              child[i]=NULL;
          }
      }
};

class Trie{
    public:
    TrieNode* root;
    

    Trie(){
        root = new TrieNode();
    }
    
    bool insert(TrieNode*& curr, char y){
        
            int x = y-'a';
            if(curr->child[x]==NULL)
            curr->child[x]=new TrieNode();
            curr=curr->child[x];
        
        bool ans = false;
        if(curr->isend==true)
        ans=true; // already exist
        curr->isend=true;
        return ans;
    }

};

class Solution {
  public:
    int countSubs(string& s) {
        // code here
        Trie T;
        int ans = 0;
        for(int i=0; i<s.size(); i++){
            TrieNode* curr = T.root;
            for(int j=i; j<s.size(); j++){
                if(T.insert(curr, s[j])==false)
                ans++;
            }
        }
        return ans;
        
    }
};