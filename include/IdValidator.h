#pragma once
#include "BaseValidators.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

class IdValidator : public BaseValidators<uint32_t> {
public:

	IdValidator() = default;
    
    bool checkLuhn(const uint32_t&);
    bool IsValid(uint32_t obj) override { return checkLuhn(obj); };
private:

};




