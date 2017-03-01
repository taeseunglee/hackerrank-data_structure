/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/

char code_to_word (node *root, string &s)
{
    node *cur_node = root;
    int cnt = 0;
    
    while (cur_node->left || cur_node->right) { // if not, cur_node is a leaf node.
        if (s[cnt++] == '1') cur_node = cur_node->right;
        else cur_node = cur_node->left;
    }
    s.erase(s.begin(), s.begin()+cnt);
    
    return cur_node->data;
}

void decode_huff (node *root, string s)
{
    string result = "";
    while (!s.empty())
        result.push_back(code_to_word(root, s));
        
    cout << result << endl;
}
