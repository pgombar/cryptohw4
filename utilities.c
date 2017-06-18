//
// Created by Ronan on 09/06/2017.
//

#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include "utilities.h"


void init(int64_t *x, int SIZE) {
    int i;
    for (i = 0; i < SIZE; i++) x[i] = 0;
}

int bit_degree(int64_t a) {
    int r = 0;
    while (a >>= 1 && a) {
        r++;
    }
    return r;
}

void print_(int64_t *r, int size) {
    int i;
    for (i = size-1; i >= 0; i--) {
        printf("%" PRId64 " ", r[i]);
    }
    printf("\n");
}

void string_(const int64_t *x, int SIZE) {
    int i;
    for (i = 0; i < SIZE; i++) {
        printf("%" PRIu64 " * (%d ^ %d)", x[i], BASE, i);
        if (i < SIZE-1) {
            printf(" + ");
        }
    }
    // printf("\n");
}

void interpret_(const int64_t *x) {
    int s = 0, i;
    for (i = 0; i < MLEN; i++) {
        s += x[i] * pow(BASE, i);
    }
    printf("%d\n", s);
}

void substraction(bigint r, const bigint x, const bigint y, int size) {
    int i;
    for (i = 0; i < size; ++i) {
        r[i] = x[i] - y[i];
    }

    //carries
    int j;
    for (j = 0; j < size - 1; ++j) {
        int test = r[j];
        if (r[j] < 0){
            while (r[j] < 0){
                r[j + 1] -= 1;
                r[j] += BASE;
            }
        }
    }
}

void addition(int64_t r[MLEN], const int64_t *x, const int64_t *y, int size) {
    int k;
    for (k = 0; k < size; ++k) {
        r[k] = x[k] + y[k];
    }

    //carries
    int l;
    for (l = 1; l < size ; ++l) {
        r[l] += r[l - 1] >> LEN;
        while (r[l - 1] >= BASE){
            r[l - 1] -= BASE;
        }
    }
}

void shift(int64_t *x, int index) {
    int i;
    for (i = MLEN - 1; i > index - 1; --i) {
        x[i] = x[i - index];
    }

    int j;
    for (j = 0; j < index; ++j) {
        x[j] = 0;
    }
}

int isNeg(int64_t *x, int size) {
    int isNeg = 0;
    int i;
    for (i = size - 1; i >= 0; --i) {
        if (x[i] != 0){
            if (x[i] < 0){
                isNeg = 1;
            }
            break;
        }
    }
    return isNeg;
}

void reduce(int64_t *x, int size){
    int i;
    for (i = 0; i < size - 1; ++i) {
        if (x[i] >= BASE){
            while (x[i] >= BASE){
                x[i+1]++;
                x[i] -= BASE;
            }
        }
    }
}
