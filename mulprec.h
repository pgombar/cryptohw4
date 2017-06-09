//
// Created by Ronan on 01/06/2017.
//

#ifndef CRYPTOHW4_MULPREC_H
#define CRYPTOHW4_MULPREC_H

#include <stdint.h>

#define LEN 14
#define MLEN 27
#define BASE 10

/* 256-bit integers in radix 2^16 */
typedef int64_t bigint[LEN]; // 14*16 = 224

//Made a multiplication
void mul_prodscan(int64_t r[MLEN], const bigint x, const bigint y);

void mul_karatsuba(int64_t r[MLEN], const bigint x, const bigint y);

void mod_reduction(int64_t r[MLEN]);

void carry(int64_t r[MLEN]);

#endif //CRYPTOHW4_MULPREC_H
