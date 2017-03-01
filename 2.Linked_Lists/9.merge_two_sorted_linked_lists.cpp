/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

Node* MergeLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method 
    Node *new_head = new Node
        ,*last_node = new_head
        ,*del = new_head;
    
    while (headA && headB) {
        if (headA->data < headB->data) {
            last_node->next = headA;
            headA = headA->next;
        }
        else {
            last_node->next = headB;
            headB = headB->next;
        }
        last_node = last_node->next;
    }
    if (headA)
        last_node->next = headA;
    if (headB)
        last_node->next = headB;
    
    new_head = new_head->next;
    delete del;
    return new_head;
}
