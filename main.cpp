#include <iostream>
#include <bitset>
#include "headers/flipflops.h"
using namespace std;

void test_register() {
    Register8 reg;
    bool CLK = 0;
    bool LOAD = 1;

    cout << "Writing 0b10101010 to register...\n";
    reg.update(0b10101010, CLK, LOAD);
    CLK = 1; reg.update(0b10101010, CLK, LOAD); // Rising edge
    cout << "Register output: " << bitset<8>(reg.output()) << endl;

    cout << "\nChanging input to 0b11111111 but disabling LOAD...\n";
    LOAD = 0;
    reg.update(0b11111111, CLK, LOAD);
    cout << "Register held value: " << bitset<8>(reg.output()) << endl;
}

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

int main() {
    cout << "⚙️  CPU Simulation - Logic Layer Test\n\n";
    test_gates();
    cout << "\n-----------------------------\n";
    test_register();
    return 0;
}
