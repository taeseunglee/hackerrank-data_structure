#include <stdio.h>
#include <stdlib.h>

int main() {
    int list_size, num_oper;
    scanf("%d %d", &list_size, &num_oper);
    
    long int *list = calloc(list_size + 1, sizeof(long int));
    for (int oper_i = 0; oper_i < num_oper; ++oper_i) {
        int a, b, k;
        scanf("%d %d %d", &a, &b, &k);
        
        list[a] += k;
        list[b+1] -= k;
    }
    
    long int max_val = 0, cur_val = 0;
    for (int list_i = 1; list_i <= list_size; ++list_i) {
        cur_val += list[list_i];
        
        if (max_val < cur_val)
            max_val = cur_val;
    }
    
    printf("%ld", max_val);

    return 0;
}
