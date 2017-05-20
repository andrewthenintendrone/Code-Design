#pragma once

template<typename T>
// returns the sum of all the numbers from 1 to input
T sumTo(T input)
{
    return (input * (input + 1) / 2);
}