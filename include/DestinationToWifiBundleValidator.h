#pragma once
#include "BaseComparison.h"
#include <iostream>

template <class T, class U>
class DestinationToWifiBundleValidator : public BaseComparison {

public:
	bool PrintValidationError(std::ostream& os) override;
	bool Validate() override;
	void setLegalFields() override { m_Destination->setGood(ValidOrNot); m_Authenticator->setGood(ValidOrNot); }
	DestinationToWifiBundleValidator(T* ptr1, U* ptr2) : m_Destination(ptr1), m_Authenticator(ptr2), ValidOrNot(false) {}

private:
	bool ValidOrNot;
	T* m_Destination;
	U* m_Authenticator;

};

template<class T, class U>
inline bool DestinationToWifiBundleValidator<T, U>::PrintValidationError(std::ostream& os){
	if (!ValidOrNot) {
		os << "Destination and Wife Bundle don't match" << std::endl;
		return false;
	}
	return true;
}

template<class T, class U>
inline bool DestinationToWifiBundleValidator<T, U>::Validate(){
	auto dest = m_Destination->get().Get();
	auto WifiBundle = m_Authenticator->get().Get();
	ValidOrNot = true;
	switch (dest){

	case ROME:
		break;

	case PRAGUE:
		break;

	case NEWYORK:
		if (WifiBundle == 2)
			ValidOrNot = false;
		break;

	case THAILAND:
		if (WifiBundle == 3)
			ValidOrNot = false;
		break;

	case INDIA:
		if (WifiBundle == 3)
			ValidOrNot = false;
		break;

	default:
		break;
	}
	setLegalFields();
	std::cout << "valid or not in wifi to destination is:     " << ValidOrNot << std::endl;
	return ValidOrNot;
}
