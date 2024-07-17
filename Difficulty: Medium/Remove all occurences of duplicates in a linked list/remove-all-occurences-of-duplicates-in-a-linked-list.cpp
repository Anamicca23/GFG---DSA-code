//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
// User function Template for C++

/* Linked List node structure

struct Node {
    int data;
    struct Node *next;
};

*/

class Solution {
  public:
   Node* removeAllDuplicates(struct Node* head) {
        // code here
        
        Node* temp=head,*tail=head,*start=NULL;
        bool check=0;
        while(tail){
            if(tail->next!=NULL&&tail->data==tail->next->data){
                tail=tail->next;
                check=1;
                continue;
            }
            if(check){
                tail=tail->next;
                check=0;
                continue;
            }
            if(!start) start=tail,temp=tail;
            else {
                start->next=tail;
                start=start->next;
            }
                    
                
                tail=tail->next;
        }
        start->next=NULL;
        
        return temp;
        
    }
};

//{ Driver Code Starts.
/* Function to print linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;

        cin >> N;

        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < N; i++) {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;
        head = ob.removeAllDuplicates(head);
        printList(head);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends