#pragma once
#include "BaseComparison.h"
#include "BaseNames.h"


template <class T, class U>
class DestinationToFlightTimeValidator : public BaseComparison {

public:
	bool PrintValidationError(std::ostream& os) override;
	bool Validate() override;
	DestinationToFlightTimeValidator(T * ptr1, U * ptr2) : m_Destination(ptr1), m_Authenticator(ptr2) {};
	void setLegalFields() override { m_Destination->setGood(); m_Authenticator->setGood(); }
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

	switch (dest)
	{
	case ROME:
		if (flightTime == 3){
			setLegalFields();
			ValidOrNot = false;
			return false;
		}
		ValidOrNot = true;
		return true;

	case PRAGUE:
		if (flightTime == 3){
			setLegalFields();
			ValidOrNot = false;
			return false;
		}
		ValidOrNot = true;
		return true;

	case NEWYORK:
		ValidOrNot = true;
		return true;

	case THAILAND:
		if (flightTime == 1){
			setLegalFields();
			ValidOrNot = false;
			return false;
		}
		ValidOrNot = true;
		return true;

	case INDIA:
		if (flightTime == 1){
			setLegalFields();
			ValidOrNot = false;
			return false;
		}
		ValidOrNot = true;
		return true;

	default:
		break;
	}
}
