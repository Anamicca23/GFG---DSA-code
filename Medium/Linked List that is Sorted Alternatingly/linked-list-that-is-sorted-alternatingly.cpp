//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
/* Function to print linked list */


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}



// } Driver Code Ends

/*
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/

class Solution {
public:
    Node * merge(Node * head1, Node * head2) {
        Node * p = head1;
        Node * q = head2;
        if (!p) return q;
        if (!q) return p;

        if (p->data > q->data) swap(p, q);

        Node * result = p;
        while (p && q) {
            Node * prev;
            while (p and q and p->data <= q->data) {
                prev = p;
                p = p->next;
            }
            prev->next = q;
            swap(p, q);
        }
        return result;

    }
    void sort(Node **head)
    {
        if (!(*head)->next) return;
        Node * first = (*head);
        Node * second = (*head)->next;
        Node * temp = (*head)->next->next;

        if (temp) {
            Node * tfirst = first;
            second->next = NULL;
            while (temp) {
                tfirst->next = temp;
                tfirst = temp;
                temp = temp->next;
                tfirst->next = NULL;
                if (temp) {
                    Node * temp_next = temp->next;
                    temp->next = second;
                    second = temp;
                    temp = temp_next;
                }
            }
            *head = merge(first, second);
        }
    }
};

//{ Driver Code Starts.
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    Solution ob;
	    ob.sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends