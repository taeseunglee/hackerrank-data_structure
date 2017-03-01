/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/
int FindMergeNode(Node *headA, Node *headB)
{
    // Complete this function
    // Do not write the main method. 
    Node *temp_a = headA, *temp_b = headB;

    // () : merged point
    // A(A)A(B)B or A(A)A
    // (B)BA(A)A    B(B)B
    while (temp_a != temp_b) {
        if (temp_a->next) temp_a = temp_a->next;
        else temp_a = headB;
        
        if (temp_b->next) temp_b = temp_b->next;
        else temp_b = headA;
    }
    return temp_a->data;
}