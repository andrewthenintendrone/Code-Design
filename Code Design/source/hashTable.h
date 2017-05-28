#pragma once

#include <string>
#include "HashFunction.h"

template<typename dataType>
struct Bucket
{
    std::string name;
    dataType data;
};

template<typename dataType>
class HashTable
{
public:
    HashTable(unsigned int size) : m_size(size), m_buckets(new Bucket<dataType>[size]) {}
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

    float loadFactor()
    {
        unsigned long usedBuckets = 0;
        for (unsigned long i = 0; i < m_size; i++)
        {
            if (m_buckets[i].name.empty())
            {
                std::cout << "empty bucket" << std::endl;
            }
        }
        return 0.5f;
    }

    // removes a bucket by erasing its name
    void remove(const std::string& key)
    {
        m_buckets[key].name.clear();
    }

private:
    HashFunction::HashFunc hashFunction;
    Bucket<dataType>* m_buckets;
    unsigned long m_size;
};