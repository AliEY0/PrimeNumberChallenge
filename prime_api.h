#pragma once
#include <time.h>

#define START_CLOCK \
    clock_t start, end; \
    double cpu_time_used;\
    start = clock(); 

#define END_CLOCK \
    end = clock(); \
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC; \
    printf("Uitvoeringstijd: %f seconden\n", cpu_time_used);

int is_prime(int n);
void first_attempt();
void second_attempt();
void third_attempt();
