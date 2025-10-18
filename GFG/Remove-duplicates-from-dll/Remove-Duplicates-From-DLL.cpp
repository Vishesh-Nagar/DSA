/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:
    Node *removeDuplicates(struct Node *head) {
        Node *curr = head;
        Node *back = head;
        while (curr != NULL) {
            if (curr->data != back->data) {
                back->next = curr;
                curr->prev = back;
                back = curr;
            }
            curr = curr->next;
        }
        back->next = NULL;
        return head;
    }
};