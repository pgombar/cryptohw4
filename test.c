//
// Created by Ronan on 01/06/2017.
//

#include <stdio.h>
#include "mulprec.h"

int test_multprec(){
    int result = 0;

    bigint a, b;
    init(a);
    init(b);

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

void runAllTest(){
    if (!test_multprec()){
        printf("Test 1 passed !");
    } else{
        printf("Test 1 failed...");
    }
}
