#pragma once

#include <string>
#include "HashFunction.h"

template<typename A, typename B>
struct Pair
{
    A first;
    B second;
};

template<typename dataType>
class HashTable
{
public:
    HashTable(unsigned int size) : m_size(size), m_data(new dataType[size]) {}
    ~HashTable() { delete[] m_data; }

    dataType& operator [] (const std::string& key)
    {
        std::cout << "normal" << std::endl;
        unsigned long hashedKey = HashFunction::default((key.c_str())) % m_size;
        return m_data[hashedKey];
    }

    const dataType& operator [] (const std::string& key) const
    {
        std::cout << "const" << std::endl;
        unsigned long hashedKey = HashFunction(key.c_str()) % m_size;
        return m_data[hashedKey];
    }

private:
    HashFunction::HashFunc hashFunction;
    dataType* m_data;
    unsigned long m_size;
};