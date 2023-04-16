#pragma once
#include "BaseComparison.h"
template <class T, class U>
class DestinationToFlightTimeValidator : public BaseComparison {

public:
	DestinationToFlightTimeValidator() = default;

	
	DestinationToFlightTimeValidator(T* ptr1, U* ptr2) : m_Destination(ptr1), m_Authenticator(ptr2) {};

private:
	T* m_Destination;
	U* m_Authenticator;


};