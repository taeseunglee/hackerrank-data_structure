/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/


node * insert(node *root, int value)
{
    node *trace = root, *new_node = new node();
    new_node->data = value;
    
    if (root) {
        while (true) {
            if (trace->data > value) { // move to the left side
                if (trace->left) trace = trace->left;
                else { trace->left = new_node; break; }
            }
            else if (trace->data < value) { // move to the right side
                if (trace->right) trace = trace->right;
                else {
                    trace->right = new_node;
                    break;
                }
            }
        }
    }
    else
        root = new_node;

   return root;
}
