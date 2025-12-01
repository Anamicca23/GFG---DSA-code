class Trie{
  public:
    Trie *child[2];
 int count;
 
 Trie(){
   for(int i=0;i<2;i++)
     child[i] = NULL;
   count=0; 
 }
 
};


class Solution {
  public:
    virtual void addInTrie(Trie *&root, int x){
   Trie *temp = root;
   for(int i=16;i>=0;i--){
     int xbit = (x>>i)&1;
 if(temp->child[xbit] == NULL)
   temp->child[xbit] = new Trie();
 temp = temp->child[xbit];
        (temp->count)++; 
   }
   return;
 }
 
    virtual int query(Trie *&root, int x, int &k){
   Trie *temp = root;
   int res=0;
   for(int i=16;i>=0;i--){
     if(!temp)
   break;
 
 int xbit = (x>>i)&1;
        int kbit = (k>>i)&1;
        
        if(kbit){
   if(temp->child[xbit] != NULL)
     res += ((temp->child[xbit])->count);
   temp = temp->child[xbit^1]; 
 }
        else{
   temp = temp->child[xbit];
 }  
   
   }
   return res;
 }
  
    virtual int cntPairs(vector<int>& arr, int k) {
      Trie *root = new Trie();
      int ans = 0;


      for(int x: arr){
     ans += query(root, x, k);
 addInTrie(root, x);
   }
      
      return ans;   
    }
};

