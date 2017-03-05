#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* primes_sieve (int limit);

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);

    int *ai = calloc(n, sizeof(int)),
        *aip = calloc(n, sizeof(int)),
        *bip = calloc(n, sizeof(int)),
        *primes = primes_sieve(10000);
    int size_ai = n, size_aip = 0,
        size_bip = 0, cur_pos = 0;
    
    for (int i = 0; i < n; ++i)
        scanf("%d", &ai[i]);
    
    for (int i = 0; i < q; ++i) {
        size_aip = 0;
        size_bip = 0;
        cur_pos = size_ai;

        while (cur_pos--) {
            int top = ai[cur_pos];
            if (top % primes[i])
                aip[size_aip++] = top;
            else
                bip[size_bip++] = top;
        }

        for (int idx_b = size_bip-1; -1 < idx_b; --idx_b)
            printf("%d\n", bip[idx_b]);

        free(bip);
        free(ai);
        ai = aip;
        size_ai = size_aip;
        
        bip = calloc(size_ai, sizeof(int));
        aip = calloc(size_ai, sizeof(int));
    }
    for (int idx_a = size_ai-1; -1 < idx_a; --idx_a)
            printf("%d\n", ai[idx_a]);
    
    free(ai);
    free(primes);
    return 0;
}

int* primes_sieve (int limit)
{
    bool *is_prime = calloc(limit, sizeof(bool));
    int *primes = calloc(limit, sizeof(int));
    int prime_size = 0;

    for (int i = 2; i < limit; ++i)
        is_prime[i] = true;

    for (int prime_i = 2; prime_i < limit; ++prime_i) {
        if (is_prime[prime_i]) {
            primes[prime_size++] = prime_i;
            printf("prime_i : %d\n", prime_i);
            for (int i = prime_i * prime_i; i< limit; i += prime_i) {
                is_prime[i] = false;
            }
        }
    }

    int *new_primes = calloc(prime_size, sizeof(int));
    for (int i = 0; i < prime_size; ++i)
        new_primes[i] = primes[i];
    
    free(primes);
    return new_primes;
}