class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        // code here
        Node * temp = head;
        int count = 1;
        while(temp->next!= NULL){ count++; temp = temp->next;}
        if(count<k) return head;
        temp = head;
        for(int i=1; i<k; i++) temp = temp->next;
        Node * a = head;
        for(int i=1; i < count-k+1; i++) a = a->next;
        swap(a->data, temp->data);
        return head;
    }
};