#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stack {
    char *str;
    struct stack *next;
};


void stack_push(struct stack **head, char *str);
char* stack_pop(struct stack **head);

int main() {
    int num_query;
    scanf("%d", &num_query);
    
    int top = -1, cur_len = 0;
    char temp[1000001] = {0,}, *cur_str = NULL;
    struct stack *stk_head = NULL;


    for (int query_i = 0; query_i < num_query; ++query_i) {
        int type;
        scanf("%d", &type);
        
        
        switch (type) {
            // append
            case 1:
            {
                stack_push(&stk_head, cur_str);
                
                scanf("%s", temp);
                cur_len += strlen(temp);

                char *new_str = calloc(cur_len + 1,sizeof(char));
                
                if (cur_str) strcpy(new_str, cur_str);
                strcat(new_str, temp);

                if (cur_str) free(cur_str);
                cur_str = new_str;
            } break;
            
            // delete
            case 2:
            {
                stack_push(&stk_head, cur_str);
                
                int pos;
                scanf("%d", &pos);
                char *new_str = calloc(cur_len-pos+1,sizeof(char));
                cur_str[cur_len-pos] = 0;
                cur_len -= pos;
                
                strcpy(new_str, cur_str);
                free(cur_str);
                cur_str = new_str;
            } break;
            
            // print
            case 3:
            {
                int pos;
                scanf("%d", &pos);
                printf("%c\n", cur_str[pos - 1]);
            } break;
            
            // undo
            case 4:
            {
                if (!stk_head) break;
                
                if (cur_str) free(cur_str);
                cur_str = stack_pop(&stk_head);
                if (cur_str) cur_len = strlen(cur_str);
                else cur_len = 0;
            } break;
        }
    }
    
    return 0;
}

void stack_push(struct stack **head, char *str)
{
    struct stack *new_node = calloc(1, sizeof(struct stack));
    if (str) {
        new_node->str = calloc(strlen(str)+1, sizeof(char));
        strcpy(new_node->str, str);
    }
    
    new_node->next = *head;
    *head = new_node;
}

char* stack_pop(struct stack **head)
{
    struct stack *temp_head = *head;
    if (temp_head) {
        char *str = temp_head->str;
        
        *head = (*head)->next;
        free(temp_head);
        
        return str;
    }
    return NULL;
}