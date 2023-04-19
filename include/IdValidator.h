#pragma once
#include "BaseValidators.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

class IdValidator : public BaseValidators<uint32_t> {
public:

    std::string PrintError();
    bool checkLuhn(const uint32_t& fieldToValidate) const;
    IdValidator() = default;
private:
    int uintLen(uint32_t num) const;

	
    
    bool IsValid(uint32_t obj) override { return checkLuhn(obj); };

};




