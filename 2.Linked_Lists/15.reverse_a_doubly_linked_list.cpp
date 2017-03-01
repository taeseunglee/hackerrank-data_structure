/*
   Reverse a doubly linked list, input list may also be empty
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* Reverse(Node* head)
{
    // Complete this function
    // Do not write the main method. 
    Node *reverse_head = NULL, *temp = NULL;
    while (head) {
        temp = head;
        head = head->next;
        temp->next = reverse_head;
        temp->prev = NULL;
        reverse_head = temp;
    }
    
    return reverse_head;
}
