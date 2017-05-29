#pragma once

#include <string>
#include "HashFunction.h"

// Bucket Struct
template<typename dataType>
class Bucket
{
public:
    Bucket() : name("") {}
    ~Bucket() {}

    // overloads
    Bucket& operator = (const Bucket& otherBucket)
    {
        name = otherBucket.name;
        data = otherBucket.data;;
        return *this;
    }

    // variables
    std::string name;
    dataType data;
};

// Hash Table class
template<typename dataType>
class HashTable
{
public:
    HashTable(unsigned int size) : m_size(size), m_buckets(new Bucket<dataType>[size]) {}
    HashTable(HashTable& otherHashTable)
    {
        m_size = otherHashTable.m_size;
        m_buckets = new Bucket<dataType>[m_size];
        *this = otherHashTable;
    }

    ~HashTable() { delete[] m_buckets; }

    dataType& operator [] (const std::string& key)
    {
        unsigned long hashedKey = HashFunction::default((key.c_str())) % m_size;
        while (true)
        {
            if (m_buckets[hashedKey].name == key || m_buckets[hashedKey].name.empty())
            {
                m_buckets[hashedKey].name = key;
                return m_buckets[hashedKey].data;
            }
            else
            {
                hashedKey++;
            }
        }
    }

    // overloads
    HashTable& operator = (const HashTable& otherHashTable)
    {
        // assert that the other Hash Table is the same size or smaller
        aieASSERT(otherHashTable.m_size <= m_size);
        for (unsigned int i = 0; i < otherHashTable.m_size; i++)
        {
            m_buckets[i] = otherHashTable.m_buckets[i];
        }
        return *this;
    }

protected:
    HashFunction::HashFunc hashFunction;
    Bucket<dataType>* m_buckets;
    unsigned int m_size;
};