#pragma once

unsigned int ELFHash(unsigned char* data, unsigned int size)
{
    unsigned int hash = 0;
    unsigned int x = 0;

    for (unsigned int i = 0; i < size; ++i)
    {
        hash = (hash << 4) + data[i];
        if ((x = hash & 0xF0000000L) != 0)
        {
            hash ^= (x >> 24);
            hash &= ~x;
        }
    }

    return (hash & 0x7FFFFFFF);
}