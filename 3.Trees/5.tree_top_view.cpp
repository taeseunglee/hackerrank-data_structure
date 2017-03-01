/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/

void left_dir (node *root) {
    if (root) {
        left_dir(root->left);
        printf("%d ", root->data);
    }
}

void right_dir (node *root) {
    if (root) {
        printf("%d ", root->data);
        right_dir(root->right);
    }
}

void top_view (node *root)
{
    if (root) {
        left_dir(root->left);
        printf("%d ", root->data);
        right_dir(root->right);
    }
}