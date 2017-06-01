#include <inttypes.h>
#include <stdio.h>

/* 256-bit integers in radix 2^16 */

typedef uint64_t bigint[16];

void mul_prodscan(uint64_t r[31], const bigint x, const bigint y) {

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

void print_(uint64_t r[31]) {
    int i;
    for (i = 30; i >= 0; i--) {
        printf("%" PRIu64 " ", r[i]);
    }
    printf("\n");
}

void init(bigint x) {
    int i;
    for (i = 0; i < 16; i++) x[i] = 0;
}

int main(void) {
    bigint a, b;
    init(a); init(b);
    
    uint64_t c[31];
    int i;
    for (i = 0; i < 31; i++) c[i] = 0;

    a[0] = 2; a[1] = 3; a[2] = 4; // 432
    b[0] = 5; b[1] = 8; b[2] = 2; // 285
    mul_prodscan(c, a, b);
    
    print_(c);
}
