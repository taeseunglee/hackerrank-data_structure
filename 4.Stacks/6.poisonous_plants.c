#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int *plant = calloc(n, sizeof(int)),
        *days = calloc(n, sizeof(int)),
        *stack = calloc(n, sizeof(int));
    int top = -1;
    for (int p_i = 0; p_i < n; ++p_i)
        scanf("%d", &plant[p_i]);
    
    int max_day = -1, min_plant = plant[0];
    stack[++top] = 0;
    for (int p_i = 1; p_i < n; ++p_i) {
        if (plant[p_i-1] < plant[p_i])
            days[p_i] = 1;
        
        if (min_plant > plant[p_i])
            min_plant = plant[p_i];

        while (-1 < top && !(plant[stack[top]] < plant[p_i])) {
            if (plant[p_i] > min_plant) {
                if (days[p_i] < days[stack[top]]+1)
                    days[p_i] = days[stack[top]]+1;
            }
            --top;
        }

        if (max_day < days[p_i])
            max_day = days[p_i];
        
        stack[++top] = p_i;
    }
    
    printf("%d", max_day);
    
    return 0;
}