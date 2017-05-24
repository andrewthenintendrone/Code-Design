#pragma once

#include <functional>

namespace HashFunction
{
    typedef std::function<unsigned long(const unsigned char*)> HashFunc;

    // HashFunction definitions
    unsigned long basicHash(const unsigned char* data);
    unsigned long BKDRHash(const unsigned char* data);
    unsigned long ELFHash(const unsigned char* data);
    unsigned long djb2Hash(const unsigned char* data);
    unsigned long SDBMHash(const unsigned char* data);

    // default HashFunction
    static HashFunc default = ELFHash;
}
