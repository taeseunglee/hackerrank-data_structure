#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int n, q;
    scanf("%d", &n);
    
    char str[1000][21] = {0,};
    for (int i = 0; i < n; ++i)
        scanf("%s", str[i]);
    
    scanf("%d", &q);
    for (int query_i = 0; query_i < q; ++query_i) {
        char query[21] = {0,};
        scanf("%s", query);
        
        int cnt = 0;
        for (int str_i = 0; str_i < n; ++str_i) {
            if (!strcmp(query,str[str_i]))
                ++cnt;
        }
        printf("%d\n", cnt);
    }
    
    return 0;
}
