#include <stdio.h>
#include <stdlib.h>

int main(){
    int n; 
    scanf("%d",&n);
    int *arr = malloc(sizeof(int) * n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       scanf("%d",&arr[arr_i]);
    }
    for(int arr_i = n-1; arr_i > -1; arr_i--){
       printf("%d ", arr[arr_i]);
    }
    return 0;
}
