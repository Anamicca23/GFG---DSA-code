//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// A Tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Utility function to create a new node
Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}

Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User function Template for C++

/*// A Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};*/

#define pb push_back
class Solution {
  public:

    /*You are required to complete below function */
    vector<int>vec;
    void dfs(Node*root){
        if(!root)return;
        dfs(root->left);
        vec.push_back(root->data);
        dfs(root->right);
    }
    
    int reverse(int low,int high){
        if(low>=high)return 0;
        if(low==high-1){
            if(vec[low]>vec[high]){
                swap(vec[low],vec[high]);
                return 1;
            }
            return 0;
        }
        int mid=(low+high)/2;
        int x=reverse(low,mid),y=reverse(mid+1,high);
        int i=low,j=mid+1;
        long long res=0;
        while(i<=mid&&j<=high){
            while(i<=mid&&vec[j]>=vec[i])i++;
            res+=(mid-i+1);
            j++;
        }
        vector<int>a;
        i=low,j=mid+1;
        while(i<=mid&&j<=high){
            if(vec[i]<vec[j])a.pb(vec[i++]);
            else a.pb(vec[j++]);
        }
        while(i<=mid)a.pb(vec[i++]);
        while(j<=high)a.pb(vec[j++]);
        for(int i=low;i<=high;i++)vec[i]=a[i-low];
        return res+x+y;
    }
    int pairsViolatingBST(int n, Node *root) {
        // your code goes here
        dfs(root);
        return reverse(0,n-1);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    getchar();

    while (t--) {

        int n;
        cin >> n;
        getchar();

        string inp;
        getline(cin, inp);

        struct Node* root = buildTree(inp);

        Solution ob;
        int ans = ob.pairsViolatingBST(n, root);
        cout << ans << endl;
    }

    return 0;
}
// } Driver Code Ends