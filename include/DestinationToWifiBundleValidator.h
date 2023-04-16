#pragma once
#include "BaseComparison.h"


template <class T, class U>
class DestinationToWifiBundleValidator : public BaseComparison {

public:
	DestinationToWifiBundleValidator() = default;

	DestinationToWifiBundleValidator(T* ptr1, U* ptr2) : m_Destination(ptr1), m_Authenticator(ptr2) {};

private:
	T* m_Destination;
	U* m_Authenticator;

};