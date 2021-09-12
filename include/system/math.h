#ifndef MATH_H
#define MATH_H

// Basic Replacable Functions
#define sqr(x) (x * x)

// Arithmatic Operators
#define ADD(a, b) (a + b)
#define SUB(a, b) (a - b)
#define DIV(a, b) (a / b)
#define MUL(a, b) (a * b)
#define MOD(a, b) (a % b)

// Boolean Math Operators (Not logic testing, but logic operations)
// Bitwise Operators
#define AND(a, b) (a & b)
#define OR(a, b) (a | b)
#define NOR(a, b) ~(a | b)
#define NOT(a) (~a)
#define NAND(a, b) ~(a & b)
#define XOR(a, b) (a ^ b)
#define XNOR(a, b) ~(a ^ b)
#define shiftLeft(a, b) (a << b) // shift a to the left b times
#define shiftRight(a, b) (a >> b) // shift a to the right b times

#define E_CONST 2.718281828459
#define PI_CONST 3.14159265358

float FACT(float n) {
    if (n >= 1) {
        return n * FACT(n - 1);
    }
    else {
        return 1;
    }
}

float POW(float a, unsigned int b) {
    if (b <= 0) {
        return 1;
    }

    if (b == 1) {
        return a;
    }

    return a * POW(a, b-1);
}





#endif