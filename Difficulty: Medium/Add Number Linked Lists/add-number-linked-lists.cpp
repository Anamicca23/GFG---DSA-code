//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
    
    Node* reverseLL(Node* &head){
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        Node* curr = head;
        Node* prev=NULL;
        Node* forward=NULL;
        
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        
        
        return prev;
        
    }
    
    
  public:
    // Function to add two numbers represented by linked list.
    Node* addTwoLists(Node* num1, Node* num2) {
        
        num1 = reverseLL(num1);
        num2 = reverseLL(num2);
        
        Node* finalHead = new Node(-1);
        Node* finalTail = finalHead;
        int carry=0;
        while(num1!=NULL || num2!=NULL || carry!=0){
            
            int v1 = (num1 == NULL) ? 0 : num1->data;
            int v2 = (num2 == NULL) ? 0 : num2->data;
            
            
            int sum = carry +v1+v2;
            carry = sum / 10;
            int digit = sum % 10;

            finalTail->next = new Node(digit);
            finalTail = finalTail->next;
            
            if (num1 != NULL) num1 = num1->next;
            if (num2 != NULL) num2 = num2->next;
            
        }

        finalHead = reverseLL(finalHead->next);
        //remove extra zeros from front
	      while(finalHead->data==0){
           finalHead = finalHead->next;
        }
     
        return finalHead;
       
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends