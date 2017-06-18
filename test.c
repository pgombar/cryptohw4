//
// Created by Ronan on 01/06/2017.
//

#include <stdio.h>
#include "mulprec.h"
#include "utilities.h"
#include "test.h"

// Product-scanning multiplication.
void test_1a(bigint a, bigint b, uint64_t c[MLEN]) {

    mul_prodscan(c, a, b);

    reduce(c, MLEN);

    string_(c, MLEN);
}

void test_1b(bigint a, bigint b, uint64_t c[MLEN]) {

    mul_karatsuba(c, a, b);

    reduce(c, MLEN);

    string_(c, MLEN);
}

void test_1c(bigint a, bigint b, uint64_t c[MLEN]) {

    mul_refined_karatsuba(c, a, b);

    reduce(c, MLEN);

    string_(c, MLEN);
}

// Modular reduction after multiplication.
void test_1d(bigint a, bigint b, uint64_t c[MLEN]) {

    mul_prodscan(c, a, b);
    mod_reduction(c);

    reduce(c, MLEN);

    // c - ((a*b) % p)
    string_(c, MLEN); printf(" - (("); string_(a, LEN); printf(") * (");
    string_(b, LEN); printf(") %% (2 ^ 221 - 3))\n");
}

// Implement a carry routine after modular multiplication:
// multiply, reduce, carry, reduce, reduce
void test1_e(bigint a, bigint b, uint64_t c[MLEN]) {

    mul_prodscan(c, a, b);
    mod_reduction(c);
    carry(c);
    mod_reduction(c); mod_reduction(c);

    int i, flag = 1;
    for (i = 0; i < MLEN; i++) {
        if (bit_degree(c[i]) >= 17) flag = 0;
    }

     printf("%s\n", flag ? "TRUE" : "FALSE");
}

void runAllTest(){
    bigint a, b;
    init(a, LEN);
    init(b, LEN);

    int64_t c[MLEN];
    init(c, MLEN);

    int i;
    for (i = 0; i < LEN; ++i) {
        a[i] = 9;
    }
    a[0] = 2; a[1] = 3; a[2] = 4; //  a = 99 999 999 999 432 in radix 10
    b[0] = 5; b[1] = 8; b[2] = 2; // b = 88 888 888 888 285 in radix 10

    printf("\n\n\ntest_1a\n");
    test_1a(a, b, c);

    printf("\n\n\ntest_1b\n");
    test_1b(a, b, c);

    printf("\n\n\ntest_1c\n");
    test_1c(a, b, c);

    printf("\n\n\ntest_1d\n");
    test_1d(a, b, c);

    printf("\n\n\ntest_1e\n");
    test1_e(a, b, c);

}

