#pragma once

//################################################//
//  basic Hash (don't ever use this)              //
//################################################//
unsigned long loseloseHash(unsigned char* data)
{
    unsigned long hash = 0;

    while (*data)
    {
        hash += *data++;
    }

    return hash;
}

//################################################//
//  BKDR Hash                                     //
//################################################//
unsigned long BKDRHash(unsigned char* data)
{
    unsigned long hash = 0;

    while (*data)
    {
        hash = (hash * 1313) + *data++;
    }

    return (hash & 0x7FFFFFFFL);
}

//################################################//
//  ELF Hash                                      //
//################################################//
unsigned long ELFHash(unsigned char* data)
{
    unsigned long hash = 0, x = 0;

    while(*data)
    {
        hash = (hash << 4) + *data++;
        if ((x = hash & 0xF0000000L))
        {
            hash ^= (x >> 24);
            hash &= ~x;
        }
    }
    return (hash & 0x7FFFFFFFL);
}

//################################################//
//  djb2 Hash                                     //
//################################################//
unsigned long djb2Hash(unsigned char* data)
{
    unsigned long hash = 5381;

    while (*data)
    {
        //  (x << 5) + x is the same as (x * 33)
        hash = ((hash << 5) + hash) + (*data++);
    }

    return hash;
}

//################################################//
//  SDBM Hash                                     //
//################################################//
unsigned long SDBMHash(unsigned char* data)
{
    unsigned long hash = 0;

    while (data)
    {
        //  ((x << 6) + (x << 16) - x) is the same as (x * 65599)
        hash = (*data++) + (hash << 6) + (hash << 16) - hash;
    }

    return hash;
}