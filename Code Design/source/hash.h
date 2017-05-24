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
//  BKDR Hash                                     //
//################################################//
unsigned int BKDRHash(unsigned char* data)
{
    unsigned int hash = 0;

    while (*data)
    {
        hash = (hash * 1313) + *data++;
    }

    return (hash & 0x7FFFFFFF);
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

//################################################//
//  djb2 Hash                                     //
//################################################//
unsigned long djb2Hash(unsigned char* data)
{
    unsigned long hash = 5381;

    while (*data)
    {
        hash = ((hash << 5) + hash) + *data++;
    }

    return hash;
}