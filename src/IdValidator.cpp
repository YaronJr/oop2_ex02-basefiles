#include "IdValidator.h"


bool IdValidator::checkLuhn(const uint32_t& number)
{
    uint32_t id = number; //to keep the id coonst

    int sum = 0, length = 0;

    while (id / 10 != 0)
    {
        id = id / 10;
        length++;
    }
    if (length != 9)
        return false;

    for (int i = 0; i <= length; i++)
    {
        int num, // The single num in the ID that will be check
            binary, // The numbers 1 or 2 that will be mult with num
            mult, // Result of multiplication of num with 1 or 2
            sum_of_mult;

        num = id % 10; // Take the last number in the ID
        id = id / 10; // Updates the ID without the last number

        if (i % 2 == 0)
            binary = 1;
        else
            binary = 2;

        mult = num * binary;

        if (mult > 9)
            sum_of_mult = (mult / 10) + (mult % 10);
        else
            sum_of_mult = mult;

        sum += sum_of_mult;
    }

    if (sum % 10 == 0)
        return true;

    return false;
}

