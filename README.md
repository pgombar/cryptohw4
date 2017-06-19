# cryptohw4
Multiprecision arithmetic in cryptography. Implementing modular reduction, Comba and Karatsuba multiplication for integers modulo 2<sup>221</sup>−3 in radix-2^16 unsigned representation.

## Usage

```
gcc -o mulprec mulprec.c && ./mulprec | bc
```