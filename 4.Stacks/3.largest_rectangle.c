#include <stdio.h>
#include <stdlib.h>

int main()
{
    int max_area = -1, area = 0;
    int stack[100000], top_idx = -1;
    int n;
    scanf("%d", &n);
    
    int building[100001] = {0,};
    for (int arr_i = 0; arr_i < n; ++arr_i)
        scanf("%d", &building[arr_i]);
    
    int i = 0;
    for (i = 0; i < n;) {
        if (top_idx == -1 || !(building[stack[top_idx]] > building[i])) {
            stack[++top_idx] = i;
            ++i;
        }
        else {
            int top_val = stack[top_idx--];
            if (top_idx != -1) // !stack.empty()
                area = building[top_val] * (i - stack[top_idx] - 1);
            else
                area = building[top_val] * i;
            if (max_area < area) 
                max_area = area;
        }
    }
    
    while (top_idx != -1) {
        int top_val = stack[top_idx--];
        if (top_idx != -1)
            area = building[top_val] * (i - stack[top_idx] - 1);
        else
            area = building[top_val] * i;
        if (max_area < area)
            max_area = area;
    }

    printf("%d", max_area);

    return 0;
}