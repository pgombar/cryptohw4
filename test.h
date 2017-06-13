//
// Created by Ronan on 01/06/2017.
//

#ifndef CRYPTOHW4_TEST_H
#define CRYPTOHW4_TEST_H

#include <stdint.h>
#include "mulprec.h"

void test_1a(bigint a, bigint b, uint64_t c[MLEN]);

void test_1b(bigint a, bigint b, uint64_t c[MLEN]);

void test_1c(bigint a, bigint b, uint64_t c[MLEN]);

void test_1d(bigint a, bigint b, uint64_t c[MLEN]);

void test1_e(bigint a, bigint b, uint64_t c[MLEN]);

//Will run all our tests
void runAllTest();

#endif //CRYPTOHW4_TEST_H
