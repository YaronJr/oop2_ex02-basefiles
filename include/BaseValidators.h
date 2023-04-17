#pragma once
#include <string>


template <class T>
class BaseValidators {
public:
	BaseValidators() = default;
	bool virtual IsValid(T obj) = 0;
private:

};