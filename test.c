//
// Created by Ronan on 01/06/2017.
//

#include <stdio.h>
#include "mulprec.h"
#include "utilities.h"
#include "test.h"

int test_multprec(){
    int result = 0;

    bigint a, b;
    init(a, LEN);
    init(b, LEN);

    uint64_t c[31];
    int i;
    for (i = 0; i < 31; i++) c[i] = 0;

    a[0] = 2; a[1] = 3; a[2] = 4;
    a[4] = 7; a[5] = 9; a[13] = 3;//30000000970432
    b[0] = 5; b[1] = 8; b[2] = 2;
    b[8] = 7; b[9] = 8; b[14] = 9;//900008700000285
    mul_prodscan(c, a, b);

    result += c[0] != 10;
    result += c[1] != 31;
    result += c[2] != 48;
    result += c[3] != 38;
    result += c[4] != 43;
    result += c[5] != 101;
    result += c[6] != 86;
    result += c[7] != 18;
    result += c[8] != 14;
    result += c[9] != 37;
    result += c[10] != 52;
    result += c[11] != 32;
    result += c[12] != 49;
    result += c[13] != 134;
    result += c[14] != 114;
    result += c[15] != 33;
    result += c[16] != 36;
    result += c[17] != 0;
    result += c[18] != 63;
    result += c[19] != 81;
    result += c[20] != 0;
    result += c[21] != 21;
    result += c[22] != 24;
    result += c[23] != 0;
    result += c[24] != 0;
    result += c[25] != 0;
    result += c[26] != 0;
    result += c[27] != 27;
    result += c[28] != 0;
    result += c[29] != 0;
    result += c[30] != 0;

    return result;
}

// Product-scanning multiplication.
void test_1a() {
    bigint a, b;
    init(a, LEN);
    init(b, LEN);

    int64_t c[MLEN];
    init(c, MLEN);

    a[0] = 2; a[1] = 3; a[2] = 4; // 432
    b[0] = 5; b[1] = 8; b[2] = 2; // 285

    mul_prodscan(c, a, b);

    // c - ((a) * (b))
    string_(c, MLEN); printf(" - (("); string_(a, LEN); printf(") * (");
    string_(b, LEN); printf("))\n");
}

// Modular reduction after multiplication.
void test_1d() {
    bigint a, b;
    init(a, LEN);
    init(b, LEN);

    int64_t c[MLEN];
    init(c, MLEN);

    a[0] = 2; a[1] = 3; a[2] = 4; // 432
    b[0] = 5; b[1] = 8; b[2] = 2; // 285

    mul_prodscan(c, a, b);
    mod_reduction(c);

    // c - ((a*b) % p)
    string_(c, MLEN); printf(" - (("); string_(a, LEN); printf(") * (");
    string_(b, LEN); printf(") %% (2 ^ 221 - 3))\n");
}

// Implement a carry routine after modular multiplication:
// multiply, reduce, carry, reduce, reduce
void test1_e() {
    bigint a, b;
    init(a, LEN);
    init(b, LEN);

    int64_t c[MLEN];
    init(c, MLEN);

    a[0] = 2; a[1] = 3; a[2] = 4; // 432
    b[0] = 5; b[1] = 8; b[2] = 2; // 285

    mul_prodscan(c, a, b);
    mod_reduction(c);
    carry(c);
    mod_reduction(c); mod_reduction(c);

    int i, flag = 1;
    for (i = 0; i < MLEN; i++) {
        if (bit_degree(c[i]) >= 17) flag = 0;
    }
    printf("%d\n", 1 - flag);
    // TODO: add check for 20 bits for a and b (isn't it only up to 16 bits?)
    // printf("%s\n", flag ? "TRUE" : "FALSE");
}

void test_1b() {
    bigint a, b;
    init(a, LEN);
    init(b, LEN);

    int64_t c[MLEN];
    init(c, MLEN);

    int i;
    for (i = 0; i < LEN; ++i) {
        a[i] = 9;
    }
    b[0]=2;



    mul_karatsuba(c, a, b);

    // c - ((a) * (b))
    string_(c, MLEN); printf(" - (("); string_(a, LEN); printf(") * (");
    string_(b, LEN); printf("))\n");
}

void test_1c() {
    bigint a, b;
    init(a, LEN);
    init(b, LEN);

    int64_t c[MLEN];
    init(c, MLEN);

    int i;
    for (i = 0; i < LEN; ++i) {
        a[i] = 9;
    }
    b[0]=2;



    mul_refined_karatsuba(c, a, b);

    // c - ((a) * (b))
    string_(c, MLEN); printf(" - (("); string_(a, LEN); printf(") * (");
    string_(b, LEN); printf("))\n");
}

void runAllTest(){
    if (!test_multprec()){
        printf("Test 1 passed !");
    } else{
        printf("Test 1 failed...");
    }

    printf("\n\n\ntest_1a\n");
    test_1a();

    printf("\n\n\ntest_1b\n");
    test_1b();

    printf("\n\n\ntest_1c\n");
    test_1c();

    printf("\n\n\ntest_1d\n");
    test_1d();

    printf("\n\n\ntest_1e\n");
    test1_e();

}

