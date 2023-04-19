#pragma once
#include "BaseValidators.h"


class NoDigitValidator : public BaseValidators<std::string> {
public:
	std::string PrintError() override { return "Can't contain digits"; }

	NoDigitValidator() = default;
	bool IsValid(std::string obj) override;

private:

};
