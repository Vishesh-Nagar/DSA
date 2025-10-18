class Solution {
  public:
    Node *reverseList(Node *head) {
        Node *prev = NULL;
        Node *curr = head;
        Node *next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    Node *addOne(Node *head) {

        head = reverseList(head);

        Node *current = head;
        int carry = 1;

        while (current != NULL) {
            int sum = current->data + carry;
            current->data = sum % 10;
            carry = sum / 10;

            if (carry == 0)
                break;

            if (current->next == NULL && carry > 0) {

                current->next = new Node(carry);
                carry = 0;
            }
            current = current->next;
        }

        head = reverseList(head);
        return head;
    }
};