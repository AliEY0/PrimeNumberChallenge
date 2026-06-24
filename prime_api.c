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
    for(int i = 0; i < n; ++i){
        if(is_prime(i) == 1){
            primes[tel++] = i;
            //printf("I: %d -> %d\n", tel, i);
        }
    }
    printf("Er zijn onder %d: %d priemgetallen gevonden\n", n, tel);
    END_CLOCK
}


