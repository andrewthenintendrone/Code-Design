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

// takes a letter and returns it's position in the alphabet (a = 1, b = 2, etc.)
int letterToNumber(char letter)
{
    // lower case
    if (letter >= 'a' && letter <= 'z')
    {
        return (int)(letter - 'a' + 1);
    }
    // upper case
    else if (letter >= 'A' && letter <= 'Z')
    {
        return (int)(letter - 'A' + 1);
    }
    // not a letter
    else
    {
        return 0;
    }
}