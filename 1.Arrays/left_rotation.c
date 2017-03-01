#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, rot;
    scanf("%d %d", &n, &rot);
    
    int *arr = calloc(n, sizeof(int));
    for (int arr_i = 0; arr_i < n; ++arr_i)
        scanf("%d", &arr[(arr_i+n-rot)%n]);
    
    for (int arr_i = 0; arr_i < n; ++arr_i)
        printf("%d ", arr[arr_i]);
    
    return 0;
}
