
/*
struct node
{
    int data;
    node* left;
    node* right;
}*/

#include <queue>
using namespace std;

void LevelOrder(node * root)
{
    if (!root) return;
    
    queue<node*> traverse;
    
    if (root) traverse.push(root);
    while (!traverse.empty()) {
        node *temp = traverse.front();
        traverse.pop();
        
        printf("%d ", temp->data);
        if (temp->left) traverse.push(temp->left);
        if (temp->right) traverse.push(temp->right);
    }
}
