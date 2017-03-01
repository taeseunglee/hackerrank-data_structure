/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Reverse(Node *head)
{
  // Complete this method
    Node *new_head = NULL
        ,*temp = NULL;
    while (head) {
        temp = head;
        head = head->next;
        temp->next = new_head;
        new_head = temp;
    }
    
    return new_head;
}
