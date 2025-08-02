#pragma once

#include "transistors.h"

// ------------------------------------------------------
// Logic Gates Built Using Transistor Logic
// ------------------------------------------------------
// These functions simulate logic gates using the behavior of
// NMOS and PMOS transistors defined in transistors.h
//
// true  == logic HIGH (1)
// false == logic LOW  (0)


// Simulates a NOT gate (inverter)
// Takes a single input and returns the opposite
inline bool not_gate(bool input) {
    bool vcc = true;   // Simulates power supply (logic HIGH)
    bool gnd = false;  // Simulates ground (logic LOW)

    // PMOS conducts when input is LOW (0), connects output to VCC (1)
    bool pull_up = pmos(input, vcc);

    // NMOS conducts when input is HIGH (1), connects output to GND (0)
    bool pull_down = nmos(input, gnd);

    // Only one of them will conduct at a time
    return pull_up + pull_down;
}


// Simulates a NAND gate
// Returns false only when both inputs are true
inline bool nand_gate(bool a, bool b) {
    bool vcc = true;
    bool gnd = false;

    // PMOS pull-up network: parallel configuration
    // At least one input LOW will conduct to VCC (true)
    bool pull_up = pmos(a, vcc) + pmos(b, vcc);

    // NMOS pull-down network: series configuration
    // Both inputs must be HIGH to conduct to GND (false)
    bool pull_down = nmos(a, nmos(b, gnd));

    // Output is true if either pull_up or pull_down is active
    return pull_up + pull_down;
}


// Simulates an AND gate using NAND + NOT
inline bool and_gate(bool a, bool b) {
    // AND is the inversion of NAND
    return not_gate(nand_gate(a, b));
}


// Simulates an OR gate using De Morgan's Law:
// A OR B = NOT(NOT A AND NOT B)
inline bool or_gate(bool a, bool b) {
    bool not_a = not_gate(a);
    bool not_b = not_gate(b);
    return not_gate(and_gate(not_a, not_b));
}


// Simulates an XOR gate (exclusive OR)
// A XOR B = (A AND NOT B) OR (NOT A AND B)
inline bool xor_gate(bool a, bool b) {
    bool part1 = and_gate(a, not_gate(b));
    bool part2 = and_gate(not_gate(a), b);
    return or_gate(part1, part2);
}
