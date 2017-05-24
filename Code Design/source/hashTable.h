#pragma once

#include <string>
#include "HashFunction.h"

template<typename A, typename B>
struct Pair
{
    A first;
    B second;
};

template<typename KeyType, typename T>
class HashTable
{
public:
    HashTable(unsigned int size) : m_size(size), m_data(new T[size]), hashFunction(HashFunction::default) {}
    ~HashTable() { delete[] m_data; }

    T& operator [] (const KeyType& key)
    {
        auto hashedKey = HashMode::hash(key) % m_size;
        return m_data[hashedKey];
    }

    const T& operator [] (const KeyType& key) const
    {
        auto hashedKey = hash(key) % m_size;
        return m_data[hashedKey];
    }

private:
    HashFunction::HashFunc hashFunction;

    T* m_data;
    unsigned int m_size;
};