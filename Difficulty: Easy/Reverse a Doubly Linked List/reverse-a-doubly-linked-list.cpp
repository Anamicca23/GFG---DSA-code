/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
     Node *reverse(Node *head) {
        Node* curr=head;
        Node* prev=NULL;
        if(curr==NULL || curr->next==NULL)
        return head;
        while(curr!=NULL)
        {
            prev=curr->prev;
            curr->prev=curr->next;
            curr->next=prev;
            curr=curr->prev;
        }
        return head=prev->prev;
    }
};