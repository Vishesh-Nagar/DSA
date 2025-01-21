class Solution {
  public:
    void deleteAllOccurOfX(struct Node **head_ref, int x) {
        Node *head = *head_ref;
        Node *temp = head;
        if (head == NULL)
            return;
        while (head->data == x) {
            head = head->next;
            head->prev = NULL;
            free(temp);
            temp = head;
        }
        *head_ref = head;
        while (temp != NULL) {
            if (temp->data == x) {
                Node *prev = temp->prev;
                Node *next = temp->next;
                prev->next = next;
                if (next != NULL)
                    next->prev = prev;
                free(temp);
                temp = next;
            } else
                temp = temp->next;
        }
    }
};