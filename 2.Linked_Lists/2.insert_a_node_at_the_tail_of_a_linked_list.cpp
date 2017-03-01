/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Insert(Node *head,int data)
{
  // Complete this method
    Node *end_node = head
        , *new_node = new Node();
    new_node->data = data;
    
    if (end_node) {
        while (end_node->next)
            end_node = end_node->next;
        end_node->next = new_node;
    }
    else
        head = new_node;
    
    return head;
}
