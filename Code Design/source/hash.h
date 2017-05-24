#pragma once

//################################################//
//  Basic Hash                                    //
//################################################//
unsigned int basicHash(unsigned char* data)
{
    unsigned int hash = 0;

    while (*data)
    {
        hash += *data++;
    }

    return hash;
}

//################################################//
//  ELF Hash                                      //
//################################################//
unsigned int ELFHash(unsigned char* data)
{
    unsigned int hash = 0, x = 0;

    while(*data)
    {
        hash = (hash << 4) + *data++;
        if ((x = hash & 0xF0000000))
        {
            hash ^= (x >> 24);
            hash &= ~x;
        }
    }
    return (hash & 0x7FFFFFFF);
}