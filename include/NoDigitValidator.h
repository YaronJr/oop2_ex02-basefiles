#pragma once
#include "BaseValidators.h"


class NoDigitValidator : public BaseValidators<std::string> {
public:

	NoDigitValidator() = default;
	bool IsValid(std::string obj) override;

private:

};



bool IsValid(std::string obj) {
    for (int i = 0; i < obj.size(); i++) {
        if (isdigit(obj[i]))
            return false;
    }
    return true;
}

