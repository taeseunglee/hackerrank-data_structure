#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        char *s = (char *)malloc(10240 * sizeof(char)),
             *stack = (char *)malloc(10240 * sizeof(char));
        scanf("%s",s);
        
        int top = -1;
        bool is_balanced = true;
        for (int s_i = 0; s[s_i]; ++s_i) {
            if (s[s_i] == '}') {
                if (stack[top] == '{')
                    --top;
                else {
                    is_balanced = false;
                    break;
                }
            }
            else if (s[s_i] == ']') {
                if (stack[top] == '[')
                    --top;
                else {
                    is_balanced = false;
                    break;
                }
            }
            else if (s[s_i] == ')') {
                if (stack[top] == '(')
                    --top;
                else {
                    is_balanced = false;
                    break;
                }
            }
            else
                stack[++top] = s[s_i];
        }
        
        if (is_balanced && top == -1) printf("YES\n");
        else printf("NO\n");
        
        free(s);
        free(stack);
    }
    
    return 0;
}
