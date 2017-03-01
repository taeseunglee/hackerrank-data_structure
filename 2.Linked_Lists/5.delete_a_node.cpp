/*
  Delete Node at a given position in a linked list 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete(Node *head, int position)
{
    Node *prev_node = head
        ,*temp = NULL;
    if (head) {
        if (position) {
            while (--position && prev_node->next) {
                prev_node = prev_node->next;
            }
            temp = prev_node->next;
            if (prev_node->next)
                prev_node->next = prev_node->next->next;
            delete temp;
        }
        else {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    return head;
}
