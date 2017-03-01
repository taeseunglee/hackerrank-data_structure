/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

// Floyd's cycle finding Algorithm
bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    Node* fast = head, *slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return 1;
    }
    
    return 0;
}
