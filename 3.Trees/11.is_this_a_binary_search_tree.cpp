/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/

struct node_stack {
    struct Node *node;
    struct node_stack *next;
};

bool is_valid(Node *root, bool dir_flag) {
    node_stack *stack_list = new node_stack(),
               *new_stack = NULL;
    if (dir_flag) // right
        stack_list->node = root->right;
    else // left
        stack_list->node = root->left;
    
    int max_data = 0,
        min_data = stack_list->node->data;
    
    while (stack_list) {
        Node *top_node = stack_list->node;
        // pop
        node_stack *del_temp = stack_list;
        stack_list = stack_list->next;
        delete del_temp;
        
        int temp_data = top_node->data;
        // ERRROR : there is a same value in the BST.
        if (temp_data == root->data) return false;
        if (max_data < temp_data) max_data = temp_data;
        if (temp_data < min_data) min_data = temp_data;

        // push
        if (top_node->left) {
            new_stack = new node_stack();
            new_stack->node = top_node->left;
            new_stack->next = stack_list;
            stack_list = new_stack;
        }
        if (top_node->right) {
            new_stack = new node_stack();
            new_stack->node = top_node->right;
            new_stack->next = stack_list;
            stack_list = new_stack;
        }
    }
    
    if (dir_flag) { // right
        if (root->data < min_data) return true;
        else return false;
    }
    else {
        if (root->data > max_data) return true;
        else return false;
    }
}

bool checkBST (Node *root) {
    if (root->left) {
        if (!checkBST(root->left)) return false;
        if (!is_valid(root, false)) return false;
    }
    if (root->right) {
        if (!checkBST(root->right)) return false;
        if (!is_valid(root, true)) return false;
    }
    
    return true;
}
