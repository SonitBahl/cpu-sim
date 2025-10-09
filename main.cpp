#include <iostream>
#include <bitset>
#include "headers/flipflops.h"
#include "headers/adder.h"

using namespace std;

// ----------------------------
// Test 8-bit Register
// ----------------------------
void test_register() {
    Register8 reg;
    bool CLK = 0;
    bool LOAD = 1;

    cout << "Writing 0b10101010 to register...\n";
    reg.update(0b10101010, CLK, LOAD);
    CLK = 1; 
    reg.update(0b10101010, CLK, LOAD); // Rising edge
    cout << "Register output: " << bitset<8>(reg.output()) << endl;

    cout << "\nChanging input to 0b11111111 but disabling LOAD...\n";
    LOAD = 0;
    reg.update(0b11111111, CLK, LOAD);
    cout << "Register held value: " << bitset<8>(reg.output()) << endl;
}

// ----------------------------
// Test Logic Gates
// ----------------------------
void test_gates() {
    cout << "=== NOT Gate ===\n";
    for (int a = 0; a <= 1; ++a)
        cout << "NOT " << a << " = " << not_gate(a) << endl;

    cout << "\n=== AND Gate ===\n";
    for (int a = 0; a <= 1; ++a)
        for (int b = 0; b <= 1; ++b)
            cout << a << " AND " << b << " = " << and_gate(a, b) << endl;

    cout << "\n=== XOR Gate ===\n";
    for (int a = 0; a <= 1; ++a)
        for (int b = 0; b <= 1; ++b)
            cout << a << " XOR " << b << " = " << xor_gate(a, b) << endl;
}

// ----------------------------
// Test Half Adder & Full Adder
// ----------------------------
void test_adders() {
    HalfAdder ha;
    FullAdder fa;

    cout << "\n=== Half Adder Truth Table ===\n";
    cout << "A B | SUM CARRY\n";
    for (int a = 0; a <= 1; ++a) {
        for (int b = 0; b <= 1; ++b) {
            cout << a << " " << b << " | " << ha.sum(a, b) << "     " << ha.carry(a, b) << "\n";
        }
    }

    cout << "\n=== Full Adder Truth Table ===\n";
    cout << "A B Cin | SUM Cout\n";
    for (int a = 0; a <= 1; ++a) {
        for (int b = 0; b <= 1; ++b) {
            for (int c = 0; c <= 1; ++c) {
                cout << a << " " << b << "  " << c << "  | " 
                     << fa.sum(a, b, c) << "   " << fa.carry(a, b, c) << "\n";
            }
        }
    }
}

// ----------------------------
// Main
// ----------------------------
int main() {
    cout << "CPU Simulation - Logic Layer Test\n\n";
    
    test_gates();
    cout << "\n-----------------------------\n";
    test_register();
    cout << "\n-----------------------------\n";
    test_adders();

    return 0;
}
