#ifndef INTERFACE_H
#define INTERFACE_H

#include <cstdint>

struct core_interface
{
    virtual void read(uint32_t space, uint64_t address) = 0;
    virtual void write(uint32_t space, uint64_t address, uint64_t data) = 0;
    virtual void simulatecycle() = 0;
    virtual void render(); //Just for graphics
    virtual void playsound(); //Just for sound
};

#endif //INTERFACE_H
