#pragma once

//################################################//
//  Basic Hash                                    //
//################################################//
unsigned long basicHash(unsigned char* data)
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
    int c;

    while (c = *data++)
    {
        //  (x << 5) + x =
        //  (x *  32) + x =
        //  (x * 33)
        hash = ((hash << 5) + hash) + c;
    }

    return hash;
}

//################################################//
//  SDBM Hash                                     //
//################################################//
unsigned long SDBMHash(unsigned char* data)
{
    unsigned long hash = 0;
    int c;

    while (c = *data++)
    {
        //  ((x << 6) + (x << 16) - x) =
        //  ((x * 64) + (x * 65536) - x) =
        //  (x * 65599) =
        hash = c + (hash << 6) + (hash << 16) - hash;
    }

    return hash;
}