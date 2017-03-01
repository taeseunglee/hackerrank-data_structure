/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* RemoveDuplicates(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
    Node *temp = NULL
        ,*trace = head;
    while (trace) {
        temp = trace->next;
        if (temp && trace->data == temp->data) {
            trace->next = temp->next;
            delete temp;
        }
        else {
            trace = trace->next;
        }
    }
    return head;
}
