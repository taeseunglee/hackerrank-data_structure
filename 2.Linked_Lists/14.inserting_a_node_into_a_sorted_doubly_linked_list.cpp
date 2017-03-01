/*
    Insert Node in a doubly sorted linked list 
    After each insertion, the list should be sorted
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* SortedInsert(Node *head,int data)
{
    // Complete this function
   // Do not write the main method. 
    Node *new_node = new Node ()
        ,*trace = head;
    new_node->data = data;
    
    if (head) {
        Node *prev = NULL;
        while (trace && trace->data < data) {
            prev = trace;
            trace = trace->next;
        }
        if (prev) {
            // prev - new_node - trace
            prev->next = new_node;
            new_node->prev = prev;
            new_node->next = trace;
            if (trace)
                trace->prev = new_node;
        }
        else {
            new_node->next = head;
            head = new_node;
        }
    }
    else {
        head = new_node;
    }
    
    return head;
}
