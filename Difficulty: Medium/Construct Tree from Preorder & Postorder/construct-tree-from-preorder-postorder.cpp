#define vi vector<int>

class Solution
{
public:
    unordered_map<int, int> post_hash;
    int nodes;

    Node *helper(int preStart, int preEnd, int postStart, int postEnd,
                 vi &pre)
    {
        if (preStart > preEnd)
            return NULL;

        Node *root = new Node(pre[preStart]);
        if (preStart == preEnd)
            return root;

        int left_subtree_node = pre[preStart + 1];
        int post_idx_of_left_subtree_node = post_hash[left_subtree_node];

        int len_of_left_subtree = post_idx_of_left_subtree_node - postStart + 1;

        root->left = helper(preStart + 1, preStart + len_of_left_subtree,
                            postStart, post_idx_of_left_subtree_node, pre);
        root->right = helper(preStart + len_of_left_subtree + 1, preEnd,
                             post_idx_of_left_subtree_node + 1, postEnd, pre);

        return root;
    }

    Node *constructTree(vector<int> &pre, vector<int> &post)
    {
        // code here
        nodes = pre.size();

        for (int i = 0; i < post.size(); i++)
        {
            post_hash[post[i]] = i;
        }

        return helper(0, nodes - 1, 0, nodes - 1, pre);
    }
};