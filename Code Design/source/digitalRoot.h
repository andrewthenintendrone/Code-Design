#pragma once

unsigned int getDigitalRoot(unsigned int input);
unsigned int numDigits(int input);

// returns the digital root of a number
unsigned int getDigitalRoot(unsigned int input)
{
    unsigned int total = 0;
    while (input)
    {
        unsigned int power = 1;
        for (unsigned int i = 1; i < numDigits(input); i++)
        {
            power *= 10;
        }
        unsigned int currentDigit = input / power;
        input -= (power * currentDigit);
        total += currentDigit;
    }

    if (total < 10)
    {
        return total;
    }
    else
    {
        return(getDigitalRoot(total));
    }
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