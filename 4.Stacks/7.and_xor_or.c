#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int num;
    scanf("%d", &num);
    
    int max_s = 0;
    int stack[1000001], top = -1;
    for (int arr_i = 0; arr_i < num; ++arr_i) {
        int cur_val;
        scanf("%d", &cur_val);
        
        while (top != -1) {
            int s = cur_val^stack[top];
            if (max_s < s)
                max_s = s;
            if (cur_val < stack[top])
                --top;
            else
                break;
        }
        stack[++top] = cur_val;
    }
    printf("%d", max_s);
    
    return 0;
}