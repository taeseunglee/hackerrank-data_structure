/*
  Print elements of a linked list on console 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

void Print(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
    Node *cur_node = head;
    while (cur_node) {
        printf("%d\n", cur_node->data);
        cur_node = cur_node->next;
    }
}
