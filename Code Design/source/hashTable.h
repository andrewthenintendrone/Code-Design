#pragma once

#include <string>
#include "HashFunction.h"

// Bucket Struct
template<typename dataType>
class Bucket
{
public:
    Bucket()
    {
        name.clear();
    }
    ~Bucket() {}

    // overloads
    Bucket& operator = (Bucket& otherBucket)
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
    HashTable(unsigned int size) : hashFunction(HashFunction::default), m_size(size), m_buckets(new Bucket<dataType>[size]) {}
    HashTable(HashTable& otherHashTable)
    {
        hashFunction = otherHashTable.hashFunction;
        m_size = otherHashTable.m_size;
        m_buckets = new Bucket<dataType>[m_size];
        *this = otherHashTable;
    }

    ~HashTable() { delete[] m_buckets; }

    // allows access to bucket data
    dataType& operator [] (const std::string& key)
    {
        // hash key
        unsigned long hashedKey = HashFunction::default((key.c_str())) % m_size;
        while (true)
        {
            // if the hashed key matches the bucket name or the bucket is empty
            if (m_buckets[hashedKey].name == key || m_buckets[hashedKey].name.empty())
            {
                // set the buckets name to key and return it
                m_buckets[hashedKey].name = key;
                return m_buckets[hashedKey].data;
            }
            // otherwise look at the next button
            else
            {
                if (hashedKey < m_size)
                {
                    hashedKey++;
                }
                else
                {
                    hashedKey = 0;
                }
            }
        }
    }

    // returns the address of a bucket specified by a key
    Bucket<dataType>& getBucket(std::string& key)
    {
        unsigned long hashedKey = HashFunction::default((key.c_str())) % m_size;
        while (true)
        {
            if (m_buckets[hashedKey].name == key || m_buckets[hashedKey].name.empty())
            {
                return m_buckets[hashedKey];
            }
            else
            {
                if (hashedKey < m_size)
                {
                    hashedKey++;
                }
                else
                {
                    hashedKey = 0;
                }
            }
        }
    }

    // overloads
    HashTable& operator = (HashTable& otherHashTable)
    {
        // assert that the other Hash Table is the same size or smaller
        aieASSERT(otherHashTable.m_size <= m_size);
        for (unsigned int i = 0; i < otherHashTable.m_size; i++)
        {
            // ignore empty buckets
            if (!otherHashTable.m_buckets[i].name.empty())
            {
                std::string key = otherHashTable.m_buckets[i].name;
                getBucket(key) = otherHashTable.getBucket(key);
            }
        }
        return *this;
    }

protected:
    HashFunction::HashFunc hashFunction;
    Bucket<dataType>* m_buckets;
    unsigned int m_size;
};