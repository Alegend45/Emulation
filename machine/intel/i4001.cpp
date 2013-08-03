#include "../../interface.h"

struct i4001 : public core_interface
{
    uint64_t addr;
    uint8_t rom[0x100];
    int cycle;
    i4001() : cycle(0)
    {
    }
    void simulatecycle()
    {
        cycle++;
        if(cycle >= 8)
        {
            cycle = 0;
        }
    }
    uint8_t read(uint32_t space, uint64_t address)
    {
        switch(space)
        {
        case 0:
            {
                //Data
                switch(cycle)
                {
                case 2:
                    {
                        return rom[addr] & 0x0F;
                        break;
                    }
                case 3:
                    {
                        return (rom[addr] >> 4) & 0x0F;
                        break;
                    }
                }
                break;
            }
        case 1:
            {
                return 0;
                break;
            }
        }
        return 0;
    }
    void write(uint32_t space, uint64_t address, uint64_t data)
    {
        switch(space)
        {
        case 0:
            {
                //Data
                switch(cycle)
                {
                case 0:
                    {
                        addr = data & 0x0F;
                        break;
                    }
                case 1:
                    {
                        addr = (data >> 4) & 0x0F;
                        break;
                    }
                }
                break;
            }
        case 1:
            {
                //I/O
                break;
            }
        }
    }
};
