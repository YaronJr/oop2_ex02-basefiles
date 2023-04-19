#pragma once
#include <string>


template <class T>
class BaseValidators {
public:
	BaseValidators() = default;
	virtual bool IsValid(T obj) = 0;
	std::string virtual PrintError() = 0;
private:

};