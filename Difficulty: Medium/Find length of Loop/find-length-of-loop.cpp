/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        if (head == NULL || head->next == NULL) return 0;

        Node *slow = head, *fast = head;

        // Step 1: Detect loop using Floyd's algorithm
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {  // Loop detected
                return countLoopLength(slow);
            }
        }
        return 0; // No loop found
    }

  private:
    int countLoopLength(Node *nodeInLoop) {
        int count = 1;
        Node *temp = nodeInLoop->next;

        while (temp != nodeInLoop) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};