#include <iostream>
#include "headers/gates.h"

using namespace std;

void test_binary_gate(const string& gate_name, bool (*gate_func)(bool, bool)) {
    cout << "=== " << gate_name << " Gate Truth Table ===\n";
    cout << "A B | OUT\n";
    cout << "-----------\n";

    for (int a = 0; a <= 1; ++a) {
        for (int b = 0; b <= 1; ++b) {
            bool result = gate_func(a, b);
            cout << a << " " << b << " |  " << result << "\n";
        }
    }
    cout << "\n";
}

void test_not_gate() {
    cout << "=== NOT Gate Truth Table ===\n";
    cout << "A | OUT\n";
    cout << "--------\n";

    for (int a = 0; a <= 1; ++a) {
        bool result = not_gate(a);
        cout << a << " |  " << result << "\n";
    }

    cout << "\n";
}

int main() {
    test_not_gate();
    test_binary_gate("NAND", nand_gate);
    test_binary_gate("AND", and_gate);
    test_binary_gate("OR", or_gate);
    test_binary_gate("XOR", xor_gate);

    return 0;
}
