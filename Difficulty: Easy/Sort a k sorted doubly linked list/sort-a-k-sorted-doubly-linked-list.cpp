//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// a node of the doubly linked list
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};


// } Driver Code Ends
// User function Template for C++

/*
// a node of the doubly linked list
class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;
    DLLNode(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
    // function to sort a k sorted doubly linked list
    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
      priority_queue<int,vector<int>,greater<int>>pq;
       DLLNode *temp1=head;
       DLLNode *temp2=head;
       while(temp1){
           pq.push(temp1->data);
           if(pq.size()==k+1){
               temp2->data=pq.top();
               temp2=temp2->next;
               pq.pop();
           }
           temp1=temp1->next;
       }
       while(!pq.empty()){
           temp2->data=pq.top();
           temp2=temp2->next;
           pq.pop();
       }
       return head;
    }
};

//{ Driver Code Starts.

// Function to insert a node at the end
// of the Doubly Linked List
void push(DLLNode **tailRef, int new_data) {
    // allocate node
    DLLNode *newNode = new DLLNode(new_data);

    // since we are adding at the end,
    // next is NULL
    newNode->next = NULL;

    newNode->prev = (*tailRef);

    // change next of tail node to new node
    if ((*tailRef) != NULL)
        (*tailRef)->next = newNode;

    (*tailRef) = newNode;
}

// Function to print nodes in a given doubly linked list
void printList(DLLNode *head) {
    // if list is empty
    if (head == NULL)
        return;

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

// Driver
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        int k;
        cin >> k;
        cin.ignore();

        DLLNode *head = new DLLNode(arr[0]);
        DLLNode *tail = head;

        // Check if the array is empty
        for (size_t i = 1; i < arr.size(); ++i) {
            push(&tail, arr[i]);
        }
        Solution obj;
        printList(obj.sortAKSortedDLL(head, k));
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends