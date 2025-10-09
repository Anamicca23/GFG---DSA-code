class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        // code here
        queue<Node*> q;
        vector<int> ans;
        bool right = false;
        q.push(root);
        
        while(!q.empty()){
            right = !right;
            int n = q.size();
            deque<int> dq;
            
            while(n--){
              auto z = q.front();
              q.pop();
              
              dq.push_back(z->data);
              
              if(z->left)
                q.push(z->left);
              if(z->right)
                q.push(z->right);
                
            }
            
            if(right){
                while(dq.size()>0){
                    ans.push_back(dq.front());
                    dq.pop_front();
                }
            }else{
                while(dq.size()>0){
                    ans.push_back(dq.back());
                    dq.pop_back();
                }
            }
            
        }
        
        return ans;
    }
};