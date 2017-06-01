//
// Created by Ronan on 01/06/2017.
//

#ifndef CRYPTOHW4_MULPREC_H
#define CRYPTOHW4_MULPREC_H

#include <stdint.h>

typedef uint64_t bigint[16];

//Made a multiplication
void mul_prodscan(uint64_t r[31], const bigint x, const bigint y);

//Display a result on the terminal
void print_(uint64_t r[31]);

//Initialise the bigint writing 0 in each cells
void init(bigint x);

#endif //CRYPTOHW4_MULPREC_H
