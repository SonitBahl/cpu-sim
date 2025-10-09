#pragma once
#include "gates.h"
#include <cstdint>

// ------------------------------------------------------
// D-Latch: Level-triggered storage element
// ------------------------------------------------------
class DLatch {
private:
    bool Q;
public:
    DLatch() : Q(false) {}

    void update(bool D, bool EN) {
        if (EN) Q = D; // Transparent when EN=1
    }

    bool output() const { return Q; }
};

// ------------------------------------------------------
// D Flip-Flop: Edge-triggered (rising edge simulation)
// ------------------------------------------------------
class DFlipFlop {
private:
    DLatch master;
    DLatch slave;
    bool last_clk;
public:
    DFlipFlop() : last_clk(false) {}

    void clock_tick(bool D, bool CLK) {
        // Master open when CLK=0
        master.update(D, !CLK);

        // Rising edge
        if (!last_clk && CLK) {
            slave.update(master.output(), true);
        }

        last_clk = CLK;
    }

    bool output() const { return slave.output(); }
};

// ------------------------------------------------------
// 1-bit Register (with Load control)
// ------------------------------------------------------
class BitRegister {
private:
    DFlipFlop ff;
public:
    void update(bool D, bool CLK, bool LOAD) {
        if (LOAD)
            ff.clock_tick(D, CLK);
        else
            ff.clock_tick(ff.output(), CLK);
    }

    bool output() const { return ff.output(); }
};

// ------------------------------------------------------
// 8-bit Register
// ------------------------------------------------------
class Register8 {
private:
    BitRegister bits[8];
public:
    void update(uint8_t data, bool CLK, bool LOAD) {
        for (int i = 0; i < 8; ++i) {
            bool bit = (data >> i) & 1;
            bits[i].update(bit, CLK, LOAD);
        }
    }

    uint8_t output() const {
        uint8_t val = 0;
        for (int i = 0; i < 8; ++i) {
            if (bits[i].output())
                val |= (1 << i);
        }
        return val;
    }
};
