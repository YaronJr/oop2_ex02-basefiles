#include "NoDigitValidator.h"

bool NoDigitValidator::IsValid(std::string obj)
{
    for (int i = 0; i < obj.size(); i++) {
        if (isdigit(obj[i]))
            return false;
    }
    return true;
}
