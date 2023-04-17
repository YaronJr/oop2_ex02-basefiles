#pragma once
#include "BaseValidators.h"


class NoDigitValidator : public BaseValidators<std::string> {
public:

	NoDigitValidator() = default;
	bool IsValid(std::string obj) override;

private:

};
