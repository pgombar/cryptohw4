#include <inttypes.h>
#include <stdio.h>
#include "mulprec.h"
#include "test.h"
#include "utilities.h"

//(a)
void mul_prodscan(int64_t r[MLEN], const bigint x, const bigint y) {

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


    r[14] = x[13] * y[1] + x[12] * y[2] + x[11] * y[3] + x[10] * y[4] + x[9] * y[5] + \
            x[8] * y[6] + x[7] * y[7] + x[6] * y[8] + x[5] * y[9] + x[4] * y[10] + \
            x[3] * y[11] + x[2] * y[12] + x[1] * y[13];

    r[15] = x[13] * y[2] + x[12] * y[3] + x[11] * y[4] + x[10] * y[5] + x[9] * y[6] + \
            x[8] * y[7] + x[7] * y[8] + x[6] * y[9] + x[5] * y[10] + x[4] * y[11] + \
            x[3] * y[12] + x[2] * y[13];

    r[16] = x[13] * y[3] + x[12] * y[4] + x[11] * y[5] + x[10] * y[6] + x[9] * y[7] + \
            x[8] * y[8] + x[7] * y[9] + x[6] * y[10] + x[5] * y[11] + x[4] * y[12] + \
            x[3] * y[13];

    r[17] = x[13] * y[4] + x[12] * y[5] + x[11] * y[6] + x[10] * y[7] + x[9] * y[8] + \
            x[8] * y[9] + x[7] * y[10] + x[6] * y[11] + x[5] * y[12] + x[4] * y[13];

    r[18] = x[13] * y[5] + x[12] * y[6] + x[11] * y[7] + x[10] * y[8] + x[9] * y[9] + \
            x[8] * y[10] + x[7] * y[11] + x[6] * y[12] + x[5] * y[13];

    r[19] = x[13] * y[6] + x[12] * y[7] + x[11] * y[8] + x[10] * y[9] + x[9] * y[10] + \
            x[8] * y[11] + x[7] * y[12] + x[6] * y[13];

    r[20] = x[13] * y[7] + x[12] * y[8] + x[11] * y[9] + x[10] * y[10] + x[9] * y[11] + \
            x[8] * y[12] + x[7] * y[13];

    r[21] = x[13] * y[8] + x[12] * y[9] + x[11] * y[10] + x[10] * y[11] + x[9] * y[12] + \
            x[8] * y[13];

    r[22] = x[13] * y[9] + x[12] * y[10] + x[11] * y[11] + x[10] * y[12] + x[9] * y[13];
    r[23] = x[13] * y[10] + x[12] * y[11] + x[11] * y[12] + x[10] * y[13];
    r[24] = x[13] * y[11] + x[12] * y[12] + x[11] * y[13];
    r[25] = x[13] * y[12] + x[12] * y[13];
    r[26] = x[13] * y[13];
}

//(b)
void mul_karatsuba(int64_t r[MLEN], const bigint x, const bigint y) {
    const int m = LEN/2;

    bigint x_0, x_1, y_0, y_1;

    //Initialization
    init(x_0, LEN);
    init(x_1, LEN);
    init(y_0, LEN);
    init(y_1, LEN);

    //Construction of our bigint
    int i;
    for (i = 0; i < m; ++i) {
        x_0[i] = x[i];
        y_0[i] = y[i];
    }

    int j;
    for (j = m; j < LEN; ++j) {
        x_1[j - m] = x[j];
        y_1[j - m] = y[j];
    }


    int64_t firstMul[MLEN];
    int64_t secondMul[MLEN];
    int64_t thirdMul[MLEN];
    init(firstMul, MLEN);
    init(secondMul, MLEN);
    init(thirdMul, MLEN);



    bigint firstAddition;
    bigint secondAddition;
    init(firstAddition, LEN);
    init(secondAddition, LEN);

    //We calculate A_o + A_1 and B_0 + B_1
    addition(firstAddition, x_0, x_1, LEN);
    addition(secondAddition, y_0, y_1, LEN);

    //(A_o + A_1)(B_0 + B_1)
    mul_prodscan(secondMul, firstAddition, secondAddition);
    reduce(secondMul, MLEN);

    //First term of the final addition
    mul_prodscan(firstMul, x_0, y_0);
    reduce(firstMul, MLEN);
    //Third term of the final addition
    mul_prodscan(thirdMul, x_1, y_1);
    reduce(thirdMul, MLEN);

    //Second term of the final addition : (A_o + A_1)(B_0 + B_1) - A_0*A_1 - B_0*B_1
    substraction(secondMul, secondMul, firstMul, MLEN);
    substraction(secondMul, secondMul, thirdMul, MLEN);


    shift(secondMul, m);
    shift(thirdMul, 2*m);

    //Final addition r = first + second + third
    addition(r, firstMul, secondMul, MLEN);
    int64_t test = r[5];
    addition(r, r, thirdMul, MLEN);
    reduce(r, MLEN);
}

//(c)
void mul_refined_karatsuba(int64_t r[MLEN], const bigint x, const bigint y) {
    const int m = LEN/2;

    bigint x_0, x_1, y_0, y_1;

    //Initialization
    init(x_0, LEN);
    init(x_1, LEN);
    init(y_0, LEN);
    init(y_1, LEN);

    //Construction of our bigint
    int i;
    for (i = 0; i < m; ++i) {
        x_0[i] = x[i];
        y_0[i] = y[i];
    }

    int j;
    for (j = m; j < LEN; ++j) {
        x_1[j - m] = x[j];
        y_1[j - m] = y[j];
    }

    int64_t L[MLEN];
    int64_t M[MLEN];
    int64_t H[MLEN];
    int64_t H_prime[MLEN];
    init(L, MLEN);
    init(M, MLEN);
    init(H, MLEN);
    init(H_prime, MLEN);

    //Construction of L
    mul_prodscan(L, x_0, y_0);
    reduce(L, MLEN);

    //Construction of H
    mul_prodscan(H, x_1, y_1);

    //H' = H + L
    //So we copy H into H'
    int k;
    for (k = 0; k < MLEN; ++k) {
        H_prime[k] = H[k];
    }
    //Then we add L
    addition(H_prime, H_prime, L, LEN);

    bigint firstSubstraction;
    bigint secondSubstraction;
    init(firstSubstraction, LEN);
    init(secondSubstraction, LEN);

    //We use tests to know if we need to compute M' = -M or not
    int firstWasNeg = 0;
    int secondWasNeg = 0;

    substraction(firstSubstraction, x_0, x_1, LEN);
    if (isNeg(firstSubstraction, LEN)){
        firstWasNeg = 1;
        substraction(firstSubstraction, x_1, x_0, LEN);
    }
    substraction(secondSubstraction, y_0, y_1, LEN);
    if (isNeg(secondSubstraction, LEN)){
        secondWasNeg = 1;
        substraction(secondSubstraction, y_1, y_0, LEN);
    }

    mul_prodscan(M, firstSubstraction, secondSubstraction);
    reduce(M, MLEN);

    //M = M' so we make the substraction H' = H' - M
    if ((firstWasNeg && secondWasNeg) || (!firstSubstraction && !secondWasNeg)){
        substraction(H_prime, H_prime, M, MLEN);
    }
        //M' = M
        //So we compute H' = H' - (-M), so H' = H' + M
    else{
        addition(H_prime, H_prime, M, MLEN);
    }

    //We compute H' = Base^m * H'
    shift(H_prime, m);
    //We compute H = Base^(2*m) * H
    shift(H, 2*m);

    //Finally, our result r = H + H' + L
    addition(r, H, H_prime, MLEN);
    addition(r, r, L, MLEN);
}

//(d)
// modular reduction: 3 * 2^3 = 24 (like slide 4 from ecc.pdf)
void mod_reduction(int64_t r[MLEN]) {
    int i;
    for (i = 0; i < LEN-1; i++) r[i] += 24 * r[i+LEN];
    int j;
    for (j = LEN - 1; j < MLEN; ++j) {
        r[j] = 0;
    }
}

//(e)
void carry(int64_t r[MLEN]) {
    int i;
    for (i = 0; i < MLEN-2; i++) {
        int64_t prev_carry = r[i] >> LEN;
        while (r[i] >= BASE){
            r[i] -= BASE;
        }
        r[i+1] += prev_carry;
    }
}

int main(void) {
    runAllTest();
    return 0;
}
