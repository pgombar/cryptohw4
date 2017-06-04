#include <inttypes.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define LEN 16
#define MLEN 31
#define BASE 10

/* 256-bit integers in radix 2^16 */
typedef uint64_t bigint[LEN]; // 14*16 = 224


void mul_prodscan(uint64_t r[MLEN], const bigint x, const bigint y) {

    r[0] = x[0] * y[0];
    r[1] = x[1] * y[0] + x[0] * y[1];
    r[2] = x[2] * y[0] + x[1] * y[1] + x[0] * y[2];
    r[3] = x[3] * y[0] + x[2] * y[1] + x[1] * y[2] + x[0] * y[3];
    r[4] = x[4] * y[0] + x[3] * y[1] + x[2] * y[2] + x[1] * y[3] + x[0] * y[4];

    r[5] = x[5] * y[0] + x[4] * y[1] + x[3] * y[2] + x[2] * y[3] + x[1] * y[4] + \
           x[0] * y[5];
    
    r[6] = x[6] * y[0] + x[5] * y[1] + x[4] * y[2] + x[3] * y[3] + x[2] * y[4] + \
           x[1] * y[5] + x[0] * y[6];
    
    r[7] = x[7] * y[0] + x[6] * y[1] + x[5] * y[2] + x[4] * y[3] + x[3] * y[4] + \
           x[2] * y[5] + x[1] * y[6] + x[0] * y[7];
    
    r[8] = x[8] * y[0] + x[7] * y[1] + x[6] * y[2] + x[5] * y[3] + x[4] * y[4] + \
           x[3] * y[5] + x[2] * y[6] + x[1] * y[7] + x[0] * y[8];
    
    r[9] = x[9] * y[0] + x[8] * y[1] + x[7] * y[2] + x[6] * y[3] + x[5] * y[4] + \
           x[4] * y[5] + x[3] * y[6] + x[2] * y[7] + x[1] * y[8] + x[0] * y[9];
    
    r[10] = x[10] * y[0] + x[9] * y[1] + x[8] * y[2] + x[7] * y[3] + x[6] * y[4] + \
            x[5] * y[5] + x[4] * y[6] + x[3] * y[7] + x[2] * y[8] + x[1] * y[9] + \
            x[0] * y[10];
    
    r[11] = x[11] * y[0] + x[10] * y[1] + x[9] * y[2] + x[8] * y[3] + x[7] * y[4] + \
            x[6] * y[5] + x[5] * y[6] + x[4] * y[7] + x[3] * y[8] + x[2] * y[9] + \
            x[1] * y[10] + x[0] * y[11];
    
    r[12] = x[12] * y[0] + x[11] * y[1] + x[10] * y[2] + x[9] * y[3] + x[8] * y[4] + \
            x[7] * y[5] + x[6] * y[6] + x[5] * y[7] + x[4] * y[8] + x[3] * y[9] + \
            x[2] * y[10] + x[1] * y[11] + x[0] * y[12];

    r[13] = x[13] * y[0] + x[12] * y[1] + x[11] * y[2] + x[10] * y[3] + x[9] * y[4] + \
            x[8] * y[5] + x[7] * y[6] + x[6] * y[7] + x[5] * y[8] + x[4] * y[9] + \
            x[3] * y[10] + x[2] * y[11] + x[1] * y[12] + x[0] * y[13];

    r[14] = x[14] * y[0] + x[13] * y[1] + x[12] * y[2] + x[11] * y[3] + x[10] * y[4] + \
            x[9] * y[5] + x[8] * y[6] + x[7] * y[7] + x[6] * y[8] + x[5] * y[9] + \
            x[4] * y[10] + x[3] * y[11] + x[2] * y[12] + x[1] * y[13] + x[0] * y[14];


    r[15] = x[15] * y[0] + x[14] * y[1] + x[13] * y[2] + x[12] * y[3] + x[11] * y[4] + \
            x[10] * y[5] + x[9] * y[6] + x[8] * y[7] + x[7] * y[8] + x[6] * y[9] + \
            x[5] * y[10] + x[4] * y[11] + x[3] * y[12] + x[2] * y[13] + x[1] * y[14] + \
            x[0] * y[15];


    r[16] = x[15] * y[1] + x[14] * y[2] + x[13] * y[3] + x[12] * y[4] + x[11] * y[5] + \
            x[10] * y[6] + x[9] * y[7] + x[8] * y[8] + x[7] * y[9] + x[6] * y[10] + \
            x[5] * y[11] + x[4] * y[12] + x[3] * y[13] + x[2] * y[14] + x[1] * y[15];

    r[17] = x[15] * y[2] + x[14] * y[3] + x[13] * y[4] + x[12] * y[5] + x[11] * y[6] + \
            x[10] * y[7] + x[9] * y[8] + x[8] * y[9] + x[7] * y[10] + x[6] * y[11] + \
            x[5] * y[12] + x[4] * y[13] + x[3] * y[14] + x[2] * y[15];

    r[18] = x[15] * y[3] + x[14] * y[4] + x[13] * y[5] + x[12] * y[6] + x[11] * y[7] + \
            x[10] * y[8] + x[9] * y[9] + x[8] * y[10] + x[7] * y[11] + x[6] * y[12] + \
            x[5] * y[13] + x[4] * y[14] + x[3] * y[15];

    r[19] = x[15] * y[4] + x[14] * y[5] + x[13] * y[6] + x[12] * y[7] + x[11] * y[8] + \
            x[10] * y[9] + x[9] * y[10] + x[8] * y[11] + x[7] * y[12] + x[6] * y[13] + \
            x[5] * y[14] + x[4] * y[15];

    r[20] = x[15] * y[5] + x[14] * y[6] + x[13] * y[7] + x[12] * y[8] + x[11] * y[9] + \
            x[10] * y[10] + x[9] * y[11] + x[8] * y[12] + x[7] * y[13] + x[6] * y[14] + \
            x[5] * y[15];

    r[21] = x[15] * y[6] + x[14] * y[7] + x[13] * y[8] + x[12] * y[9] + x[11] * y[10] + \
            x[10] * y[11] + x[9] * y[12] + x[8] * y[13] + x[7] * y[14] + x[6] * y[15];

    r[22] = x[15] * y[7] + x[14] * y[8] + x[13] * y[9] + x[12] * y[10] + x[11] * y[11] + \
            x[10] * y[12] + x[9] * y[13] + x[8] * y[14] + x[7] * y[15];

    r[23] = x[15] * y[8] + x[14] * y[9] + x[13] * y[10] + x[12] * y[11] + x[11] * y[12] + \
            x[10] * y[13] + x[9] * y[14] + x[8] * y[15];

    r[24] = x[15] * y[9] + x[14] * y[10] + x[13] * y[11] + x[12] * y[12] + x[11] * y[13] + \
            x[10] * y[14] + x[9] * y[15];

    r[25] = x[15] * y[10] + x[14] * y[11] + x[13] * y[12] + x[12] * y[13] + x[11] * y[14] + \
            x[10] * y[15];

    r[26] = x[15] * y[11] + x[14] * y[12] + x[13] * y[13] + x[12] * y[14] + x[11] * y[15];
    r[27] = x[15] * y[12] + x[14] * y[13] + x[13] * y[14] + x[12] * y[15];
    r[28] = x[15] * y[13] + x[14] * y[14] + x[13] * y[15];
    r[29] = x[15] * y[14] + x[14] * y[15];
    r[30] = x[15] * y[15];
}

// modular reduction: 3 * 2^3 = 24 (like slide 4 from ecc.pdf)
void mod_reduction(uint64_t r[MLEN]) {
    int i;
    for (i = 0; i < LEN-1; i++) r[i] += 24 * r[i+LEN];
}

void carry(uint64_t r[MLEN]) {
    int i;
    for (i = 0; i < MLEN-2; i++) {
        uint64_t prev_carry = r[i] >> LEN; 
        int shift = sizeof(uint64_t)*8 - LEN;
        r[i] = r[i] << shift >> shift; // clear all but the first 16 bits
        r[i+1] += prev_carry;
    }
}

// =================================================
// HELPER FUNCTIONS
void init(uint64_t *x, int SIZE) {
    int i;
    for (i = 0; i < SIZE; i++) x[i] = 0;
}

int bit_degree(uint64_t a) {
    int r = 0;
    while (a >>= 1) {
        r++;
    }
    return r;
}

void print_(uint64_t r[MLEN]) {
    int i;
    for (i = MLEN-1; i >= 0; i--) {
        printf("%" PRIu64 " ", r[i]);
    }
    printf("\n");
}

void string_(const uint64_t *x, int SIZE) {
    int i;
    for (i = 0; i < SIZE; i++) {
        printf("%d * (%d ^ %d)", x[i], BASE, i);
        if (i < SIZE-1) {
            printf(" + ");
        }
    }
    // printf("\n");
}

void interpret_(const uint64_t *x) {
    int s = 0, i;
    for (i = 0; i < MLEN; i++) {
        s += x[i] * pow(BASE, i);
    }
    printf("%d\n", s);
}
// =================================================

// Product-scanning multiplication.
void test_1a(bigint a, bigint b, uint64_t *c) {
    mul_prodscan(c, a, b);

    // c - ((a) * (b))
    string_(c, MLEN); printf(" - (("); string_(a, LEN); printf(") * (");
    string_(b, LEN); printf("))\n");
}

// Modular reduction after multiplication.
void test_1d(bigint a, bigint b, uint64_t *c) {
    mul_prodscan(c, a, b);
    mod_reduction(c);

    // c - ((a*b) % p)
    string_(c, MLEN); printf(" - (("); string_(a, LEN); printf(") * (");
    string_(b, LEN); printf(") %% (2 ^ 221 - 3))\n");
}

// Implement a carry routine after modular multiplication:
// multiply, reduce, carry, reduce, reduce
void test1_e(bigint a, bigint b, uint64_t *c) {
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

int main(void) {
    bigint a, b;
    init(a, LEN); init(b, LEN);
    
    uint64_t c[MLEN], d[MLEN];
    init(c, MLEN); init(d, MLEN);

    a[0] = 2; a[1] = 3; a[2] = 4; // 432
    b[0] = 5; b[1] = 8; b[2] = 2; // 285

    test_1a(a, b, c);
    test_1d(a, b, c);
    test1_e(a, b, c);
}
