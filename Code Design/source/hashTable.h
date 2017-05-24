#pragma once

#include <string>
#include "hashes.h"

template<typename KeyType, typename T>
class HashTable
{
public:
    HashTable(unsigned int size) : m_size(size), m_data(new T[size]) {}
    ~HashTable() { delete[] m_data; }

    T& operator [] (const KeyType& key)
    {
        auto hashedKey = hash(key) % m_size;
        return m_data[hashedKey];
    }

    const T& operator [] (const KeyType& key) const
    {
        auto hashedKey = hash(key) % m_size;
        return m_data[hashedKey];
    }

private:
    unsigned int hashFunction(const std::string& key);

    T* m_data;
    unsigned int m_size;
};