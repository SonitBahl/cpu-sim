#pragma once

// ------------------------------------------------------
// Transistor-level logic simulation in C++
// ------------------------------------------------------
// NMOS (n-type metal-oxide semiconductor) acts like a switch:
// - Conducts when gate is HIGH (true)
// - Blocks when gate is LOW (false)
//
// PMOS (p-type) behaves oppositely:
// - Conducts when gate is LOW (false)
// - Blocks when gate is HIGH (true)
//
// These functions simulate that behavior.


// Simulates an NMOS transistor
// gate: the control signal (true = ON, false = OFF)
// source: the value we want to pass through the transistor
// returns: source if the gate is ON, else false
inline bool nmos(bool gate, bool source) {
    if (gate == true) {
        // Transistor conducts; pass the source through
        return source;
    } else {
        // Transistor is off; output is pulled down
        return false;
    }
}


// Simulates a PMOS transistor
// gate: the control signal (true = OFF, false = ON)
// source: the value we want to pass through the transistor
// returns: source if the gate is OFF, else false
inline bool pmos(bool gate, bool source) {
    if (gate == false) {
        // Transistor conducts; pass the source through
        return source;
    } else {
        // Transistor is off; output is pulled down
        return false;
    }
}
