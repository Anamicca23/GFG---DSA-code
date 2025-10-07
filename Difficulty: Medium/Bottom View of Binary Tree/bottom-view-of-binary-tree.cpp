/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        unordered_map<Node*,int>omap;
        map<int,vector<Node*>>mapForOrder;
        
        queue<Node*>q;
        q.push(root);
        omap[root]=0;
        mapForOrder[0].push_back(root);
        
        while(!q.empty()) {
            int counter=q.size();
            for(int i=0;i<counter;i++) {
                Node* vertex=q.front();
                q.pop(); 
                int location=omap[vertex];
                if(vertex->left!=NULL) {
                    q.push(vertex->left);
                    omap[vertex->left]=location-1;
                    mapForOrder[location-1].push_back(vertex->left);
                }
                
                if(vertex->right!=NULL) {
                    q.push(vertex->right);
                    omap[vertex->right]=location+1;
                    mapForOrder[location+1].push_back(vertex->right);
                }
            }
           
        }
        
        
        vector<int>ans;
        
        for(auto i:mapForOrder) {
            ans.push_back(i.second[i.second.size()-1]->data);
        }
        return ans;
        
    }
};