class Solution {
  public:
    struct Node {
        int freq;
        int minIdx;
        Node *left, *right;
        
        Node(int f, int idx) {
            freq = f;
            minIdx = idx;
            left = right = NULL;
        }
    };
    
    struct cmp {
        bool operator()(Node* a, Node* b) {
            if (a->freq == b->freq)
                return a->minIdx > b->minIdx;
            return a->freq > b->freq;
        }
    };
    
    void preorder(Node* root, string curr, vector<string> &res) {
        if (!root) return;
        
        if (!root->left && !root->right) {
            res.push_back(curr);
            return;
        }
        
        preorder(root->left, curr + "0", res);
        preorder(root->right, curr + "1", res);
    }
    
    vector<string> huffmanCodes(string &s, vector<int> f) {
        priority_queue<Node*, vector<Node*>, cmp> pq;
        
        for (int i = 0; i < s.size(); i++) {
            pq.push(new Node(f[i], i));
        }
        
        if (pq.size() == 1) return {"0"};
        
        while (pq.size() > 1) {
            Node* left = pq.top(); pq.pop();
            Node* right = pq.top(); pq.pop();
            
            Node* parent = new Node(
                left->freq + right->freq,
                min(left->minIdx, right->minIdx)
            );
            
            parent->left = left;
            parent->right = right;
            
            pq.push(parent);
        }
        
        vector<string> res;
        preorder(pq.top(), "", res);
        return res;
    }
};