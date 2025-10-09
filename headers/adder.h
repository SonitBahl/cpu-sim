#pragma once
#include "gates.h"

// ------------------------------------------------------
// Half Adder
// Inputs: A, B
// Outputs: SUM, CARRY
// ------------------------------------------------------
class HalfAdder {
public:
    bool sum(bool A, bool B) {
        return xor_gate(A, B);
    }

    bool carry(bool A, bool B) {
        return and_gate(A, B);
    }
};

// ------------------------------------------------------
// Full Adder
// Inputs: A, B, Cin
// Outputs: SUM, Cout
// ------------------------------------------------------
class FullAdder {
private:
    HalfAdder ha1, ha2;
public:
    bool sum(bool A, bool B, bool Cin) {
        bool s1 = ha1.sum(A, B);
        return ha2.sum(s1, Cin);
    }

    bool carry(bool A, bool B, bool Cin) {
        bool c1 = ha1.carry(A, B);
        bool c2 = ha2.carry(xor_gate(A, B), Cin);
        return or_gate(c1, c2);
    }
};
