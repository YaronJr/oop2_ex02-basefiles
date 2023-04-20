#pragma once
#include "BaseComparison.h"
#include "BaseNames.h"
#include <iostream>


template <class T, class U>
class DestinationToFlightTimeValidator : public BaseComparison {

public:
	bool PrintValidationError(std::ostream& os) override;
	bool Validate() override;
	DestinationToFlightTimeValidator(T * ptr1, U * ptr2) : m_Destination(ptr1), m_Authenticator(ptr2), ValidOrNot(false) {}
	void setLegalFields() override { m_Destination->setGood(ValidOrNot); m_Authenticator->setGood(ValidOrNot); }
private:
	bool ValidOrNot;
	T* m_Destination;
	U* m_Authenticator;

};



template<class T, class U>
inline bool DestinationToFlightTimeValidator<T, U>::PrintValidationError(std::ostream& os){
	if (!ValidOrNot) {
		os << "Destination and flight time don't match" << std::endl;
		return false;
	}
	return true;
	
}

template<class T, class U>
inline bool DestinationToFlightTimeValidator<T, U>::Validate()
{
	int dest = m_Destination->get().Get();
	int flightTime = m_Authenticator->get().Get();
	ValidOrNot = true;
	switch (dest){

	case ROME:
		if (flightTime == 3)
			ValidOrNot = false;
		break;
		
	case PRAGUE:
		if (flightTime == 3)
			ValidOrNot = false;
		break;

	case NEWYORK:
		break;

	case INDIA:
		if (flightTime == 1)
			ValidOrNot = false;
		break;
		
	case THAILAND:
		if (flightTime == 1)
			ValidOrNot = false;
		break;

	default:
		break;
	}
	setLegalFields();
	std::cout << "valid or not in estination to flight time is:     " << ValidOrNot << std::endl;
	return ValidOrNot;
}
