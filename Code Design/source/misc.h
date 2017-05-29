#pragma once

// miscellaneous functions

unsigned int getDigitalRoot(unsigned int input);
unsigned int numDigits(int input);

// returns the digital root of a number
unsigned int getDigitalRoot(unsigned int input)
{
    return (input - (9 * ((input - 1) / 9)));
}

// returns the number of digits in a number
unsigned int numDigits(int input)
{
    unsigned int digits = 0;

    do
    {
        input /= 10;
        digits++;
    } while (input != 0);

    return digits;
}

// returns the sum of all the numbers from 1 to input
int sumTo(const int& input)
{
    return (input * (input + 1) / 2);
}