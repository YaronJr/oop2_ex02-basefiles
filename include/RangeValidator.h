#pragma once
#include "BaseValidators.h"

template <class T>
class RangeValidator : public BaseValidators {
public:
	RangeValidator(int min, int max) : m_Min(min), m_Max(max) {};

private:
	int m_Min, m_Max;

};


