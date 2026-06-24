#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "prime_api.h"
#include <stdbool.h>
int is_prime(int n) {
    if(n < 2) return -1;
    if(n == 2) return 1;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0)
            return -1;
    }
    return 1;
}

void third_attempt(){
    START_CLOCK
    int n = 1000000000; 
    const int S = 100000;
    int nsqrt = (int)sqrt((double)n);
    char *is_prime = (char *)malloc((nsqrt + 2) * sizeof(char));
    memset(is_prime, 1, nsqrt + 2);
    int *primes = (int *)malloc((nsqrt + 1) * sizeof(int));
    int prime_count = 0;
    for (int i = 2; i <= nsqrt; i++) {
        if (is_prime[i]) {
            primes[prime_count++] = i;

            if ((long long)i * i <= nsqrt) {
                for (int j = i * i; j <= nsqrt; j += i)
                    is_prime[j] = 0;
            }
        }
    }
    int result = 0;
    char *block = (char *)malloc(S * sizeof(char));
    for (int k = 0; k * S <= n; k++) {
        memset(block, 1, S);
        int start = k * S;
        for (int idx = 0; idx < prime_count; idx++) {
            int p = primes[idx];
            int start_idx = (start + p - 1) / p;
            int j = ((start_idx > p ? start_idx : p) * p) - start;
            for (; j < S; j += p)
                block[j] = 0;
        }
        if (k == 0) {
            block[0] = 0;
            block[1] = 0;
        }
        for (int i = 0; i < S && start + i <= n; i++) {
            if (block[i])
                result++;
        }
    }
    free(block);
    free(primes);
    free(is_prime);
    printf("Er zijn onder %d: %d priemgetallen gevonden\n", n, result);
    END_CLOCK
}

void second_attempt(){
    START_CLOCK
    int n = 1000000000;
    int tel = 0;
    bool* prime = malloc((n + 1) * sizeof(bool));
    for (int i = 0; i <= n; i++)
        prime[i] = true;
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++) {
        if (prime[p])
            ++tel;
    }
    printf("Er zijn onder %d: %d priemgetallen gevonden\n", n, tel);
    END_CLOCK
}

void first_attempt(){
    START_CLOCK
    int n = 1000000;
    int tel = 0;
    int *primes = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; ++i) {
        if(is_prime(i) == 1) {
            primes[tel++] = i;
            //printf("I: %d -> %d\n", tel, i);
        }
    }
    printf("Er zijn onder %d: %d priemgetallen gevonden\n", n, tel);
    END_CLOCK
}


