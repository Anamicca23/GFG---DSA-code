//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    Node *reverse(Node *head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        Node *curr = head, *prev = NULL, *fut = NULL;
        
        while(curr){
            fut = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fut;
        }
        
        return prev;
    }
    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        
        Node *temp1 = head1;
        Node *temp2 = head2;
        
        while(temp1 && !(temp1->data)){
            temp1 = temp1->next;
        }
        
        while(temp2 && !(temp2->data)){
            temp2 = temp2->next;
        }
        
        if(temp2==NULL && temp1==NULL){
            return new Node(0);
        }
        
        if(!temp1) return temp2;
        if(!temp2) return temp1;
        
        head1 = temp1, head2 = temp2;
        
        int count1 = 1;
        int count2 = 1;
        while(temp1->next){
            count1++;
            temp1 = temp1->next;
        }
        
        while(temp2->next){
            count2++;
            temp2 = temp2->next;
        }
        
        Node *largest = NULL;
        
        if(count1 == count2){
            Node *node1 = head1;
            Node *node2 = head2;
            while(node1 && (node1->data == node2->data)){
                node1 = node1->next;
                node2 = node2->next;
            }
            if(!node1) return new Node(0);
            largest = node1->data > node2->data? head1 : head2;
        }
        else{
            largest = count1>count2? head1 : head2; 
        }
        
        if(largest == head2){
            swap(temp1,temp2);
        }
        
        Node *smallest = largest == head1? head2 : head1;
        
        largest = reverse(largest);
        smallest = reverse(smallest);
        
        Node *ans = new Node(0);
        Node *tail = ans;
        
        bool carry = 0;
        bool key = 0;
        
        while(temp1 && temp2){
            key = 0;
            if(temp1->data == 0 && carry){
                temp1->data = 9;
                key = 1;
            }
            else{
                temp1->data -= carry;
            }
            if(temp1->data < temp2->data){
                carry = 1;
                temp1->data += 10;
            }
            else{
                if(!key) carry = 0;
            }
            tail->next = new Node(temp1->data - temp2->data);
            tail = tail->next;
            
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        
        while(temp1){
            if(temp1->data == 0 && carry){
                temp1->data = 9;
                carry = 1;
            }
            else{
                temp1->data -= carry;
                carry = 0;
            }
            tail->next = new Node(temp1->data);
            tail = tail->next;
            
            temp1 = temp1->next;
        }
        
        ans = ans->next;
        ans = reverse(ans);
        
        while(!ans->data){
            ans = ans->next;
        }
        
        return ans;
    }

};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends