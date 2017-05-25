#pragma once

template<typename dataType>
// returns the sum of all the numbers from 1 to input
dataType sumTo(dataType input)
{
    return (input * (input + 1) / 2);
}