#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int n[3], *h[3], sum[3] = {0,}; 
    scanf("%d %d %d", &n[0], &n[1], &n[2]);
    
    for (int i = 0; i < 3; ++i) {
        h[i] = malloc(sizeof(int) * n[i]);
        
        for(int h_i = 0; h_i < n[i]; h_i++){
            scanf("%d",&h[i][h_i]);
            sum[i] += h[i][h_i];
        }
    }
    
    int top[3] = {0,};
    while (1) {
        if (sum[0] != sum[1]) {
            if (sum[0] < sum[1])
                sum[1] -= h[1][top[1]++];
            else
                sum[0] -= h[0][top[0]++];
        }
        else if (sum[1] != sum[2]) {
            if (sum[1] < sum[2])
                sum[2] -= h[2][top[2]++];
            else
                sum[1] -= h[1][top[1]++];
        }
        else { // sum[0] == sum[1] == sum[2]
            break;
        }
    }

    printf("%d", sum[0]);
    
    return 0;
}
