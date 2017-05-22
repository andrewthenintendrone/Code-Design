#pragma once

template<typename T>
class DynamicArray
{
public:
    // constructor
    DynamicArray(unsigned int initialSize)
    {
        DynamicArray array;
        array.data = new array[initialSize];
        array.allocatedElements = initialSize;
        array.usedElements = 0;
    }

private:
    Array* arrayPointer; // change this
    unsigned int allocatedMemory;
    unsigned int allocatedElements;
    unsigned int usedElements;
};