/*
  Insert Node at a given position in a linked list 
  head can be NULL 
  First element in the linked list is at position 0
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node *head, int data, int position)
{
  // Complete this method
    Node *pos_node = head
        , *new_node = new Node();
    new_node->data = data;
    
    if (!position) {
        new_node->next = head;
        head = new_node;
    }
    else if (pos_node) {
        while (--position && pos_node->next)
            pos_node = pos_node->next;
        new_node->next = pos_node->next;
        pos_node->next = new_node;
    }
    else {
        head = new_node;
    }
    
    return head;
}