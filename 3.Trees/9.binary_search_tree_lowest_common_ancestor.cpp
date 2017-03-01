/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/


node * lca(node * root, int v1,int v2)
{
    node *lca_node = root;
    if (v1 > v2) { /* swap */
        int temp = v1;
        v1 = v2;
        v2 = temp;
    }
    
    while (true) {
        int temp_data = lca_node->data;

        if (v1 < temp_data && v2 < temp_data) {
            /* LCA is located at a left side of current node */
            lca_node = lca_node->left;
        }
        else if (temp_data < v1 && temp_data < v2) {
            /* LCA is located at a right side of current node */
            lca_node = lca_node->right;
        }
        else {
            /* find the lca node! */
            break;
        }
    }

    return lca_node;
}

