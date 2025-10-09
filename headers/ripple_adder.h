#pragma once
#include "adder.h"
#include <bitset>
#include <iostream>

// ------------------------------------------------------
// 4-Bit Ripple Carry Adder
// ------------------------------------------------------
// Uses 4 FullAdders chained together.
// Adds two 4-bit binary numbers (A and B) + carry-in.
// Produces a 4-bit sum and a carry-out.
// ------------------------------------------------------
class RippleAdder4 {
private:
    FullAdder fa[4];
public:
    struct Result {
        uint8_t sum;   // 4-bit result
        bool carry_out;
    };

    Result add(uint8_t A, uint8_t B, bool Cin = 0) {
        Result r;
        bool carry = Cin;
        uint8_t sum_val = 0;

        for (int i = 0; i < 4; ++i) {
            bool a_bit = (A >> i) & 1;
            bool b_bit = (B >> i) & 1;

            bool s = fa[i].sum(a_bit, b_bit, carry);
            carry = fa[i].carry(a_bit, b_bit, carry);

            sum_val |= (s << i);
        }

        r.sum = sum_val & 0xF;
        r.carry_out = carry;
        return r;
    }
};
