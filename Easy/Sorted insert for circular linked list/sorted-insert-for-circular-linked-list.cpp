//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
/* structure for a Node */
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
  
};


// } Driver Code Ends
/* structure for a node */
/*
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
  
};
 */
 
// This function should return head of
// the modified list
class Solution
{
    public:
    Node *sortedInsert(Node* head, int data)  // simply for checking if head is null or not 
    {
        if(head == NULL) {
    Node* newNode = new Node(data);
    newNode->next = newNode;
    return newNode;
}
       if(head->data>=data)  // if element is to be inserted first
       {
           Node* dum=new Node(data);
           dum->next=head;
           Node* temp=head;
           while(temp->next!=head)
           {
               temp=temp->next;
           }
           temp->next=dum;
           return dum;
       }
       else if(head->data<data)  // if element is inserted between or at the end 
       {
           Node*temp=head->next;
           Node* prev=head;
           while(temp->data<data and temp!=head)
           {
               prev=temp;
               temp=temp->next;
           }
           if(temp==head)  // if element is inserted at end 
           {
               Node* dum3=new Node(data);
               prev->next=dum3;
               dum3->next=temp;
               return head;
           }
           else {  // for simply inserting the element in between 
               Node* dum2=new Node(data);
           prev->next=dum2;
           dum2->next=temp;
           return head;
               
           }
           
           
       }
       return NULL;
    }
};


//{ Driver Code Starts.

/* Function to print Nodes in a given linked list */
void printList(struct Node *start)
{
  struct Node *temp;

  if(start != NULL)
  {
    temp = start;
    do { printf("%d ", temp->data);
      temp = temp->next;
    } while(temp != start);
    printf("\n");
  }
}
/* Driver program to test above functions */
int main()
{
int t,n,x;
scanf("%d",&t);
int arr;
  while(t--){
  scanf("%d",&n);
  int list_size, i;
  
  /* start with empty linked list */
  struct Node *start = NULL;
  struct Node *temp,*r;
  
  
    /* Create linked list from the array arr[].
    Created linked list will be 1->2->11->56->12 */
    if(n>0){
      scanf("%d",&arr);
    
    temp = new Node(arr);
    start=temp;
    r=start;
    }
    for (i = 0; i<n-1; i++)
    {
        scanf("%d",&arr);
        temp = new Node(arr);
        r->next=temp;
        r=r->next;
    }
    
    if(n>0)
    temp->next=start;
 
    scanf("%d",&x);
    Solution ob;
    start = ob.sortedInsert(start,x);
    printList(start);
    r=start;
    while(r!=start->next)
    {

      temp=start;
      start=start->next;
      free(temp);
    }
    free(start);
}
  return 0;
}

// } Driver Code Ends