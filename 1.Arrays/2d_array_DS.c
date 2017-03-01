#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(){
    int arr[6][6];
    for(int arr_i = 0; arr_i < 6; arr_i++){
       for(int arr_j = 0; arr_j < 6; arr_j++){
          scanf("%d",&arr[arr_i][arr_j]);
       }
    }
    int max_sum = INT_MIN;
    
    for(int arr_i = 0; arr_i < 4; arr_i++){
       for(int arr_j = 0; arr_j < 4; arr_j++){
           int temp_sum = arr[arr_i+1][arr_j+1];
           for (int i = 0; i < 3; i ++)
               temp_sum += arr[arr_i][arr_j+i] + arr[arr_i+2][arr_j+i];
           if (max_sum < temp_sum)
               max_sum = temp_sum;
       }
    }
    printf("%d", max_sum);
    
    return 0;
}
