//
// Created by Ronan on 09/06/2017.
//

#ifndef CRYPTOHW4_UTILITIES_H
#define CRYPTOHW4_UTILITIES_H

#include <stdint.h>
#include "mulprec.h"

//Display a result on the terminal
void print_(int64_t *r, int size);

//Initialise the bigint writing 0 in each cells
void init(int64_t *x, int SIZE);

int bit_degree(int64_t a);

void string_(const int64_t *x, int SIZE);

void interpret_(const int64_t *x);

void substraction(bigint r, const int64_t *x, const int64_t *y, int size);

void addition(int64_t r[MLEN], const int64_t *x, const int64_t *y, int size);

void shift(int64_t *x, int index);

int isNeg(int64_t *x, int size);

void reduce(int64_t *x, int size);

#endif //CRYPTOHW4_UTILITIES_H
