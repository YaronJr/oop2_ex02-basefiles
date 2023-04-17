#pragma once
#include "BaseValidators.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

class IdValidator : public BaseValidators<uint32_t> {
public:

	IdValidator() = default;
    
    bool checkLuhn(const uint32_t);
    bool IsValid(uint32_t obj) override { return checkLuhn(obj); };
private:

};





bool IdValidator::checkLuhn(const uint32_t cardNo)
{
    int nDigits = 1;
    int num = cardNo;
    while (num != 0) {
        num /= 10;
        nDigits++;
    }
    num = cardNo;
    int nSum = 0, isSecond = false;
    for (int i = nDigits - 1; i >= 0; i--) {
        int d = num % 10;
        num /= 10;

        if (isSecond == true)
            d = d * 2;

        // We add two digits to handle
        // cases that make two digits after
        // doubling
        nSum += d / 10;
        nSum += d % 10;

        isSecond = !isSecond;
    }
    return (nSum % 10 == 0);
}