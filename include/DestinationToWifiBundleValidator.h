#pragma once
#include "BaseComparison.h"
#include <iostream>

template <class T, class U>
class DestinationToWifiBundleValidator : public BaseComparison {

public:
	bool PrintValidationError(std::ostream& os) override;
	bool Validate() override;
	void setLegalFields() override { m_Destination->setGood(); m_Authenticator->setGood(); }
	DestinationToWifiBundleValidator(T* ptr1, U* ptr2){
		m_Destination = ptr1;
		m_Authenticator = ptr2;
	};

private:
	bool ValidOrNot;
	T* m_Destination;
	U* m_Authenticator;

};

template<class T, class U>
inline bool DestinationToWifiBundleValidator<T, U>::PrintValidationError(std::ostream& os){
	if (!ValidOrNot) {
		os << "Destination and flight time don't match" << std::endl;
		return false;
	}
	return true;
}

template<class T, class U>
inline bool DestinationToWifiBundleValidator<T, U>::Validate(){
	auto dest = m_Destination->get().Get();
	auto WifiBundle = m_Authenticator->get().Get();
	switch (dest)
	{
	case ROME:
		ValidOrNot = true;
		return true;

	case PRAGUE:
		ValidOrNot = true;
		return true;

	case NEWYORK:
		if (WifiBundle == 1){
			setLegalFields();
			ValidOrNot = false;
			return false;
		}
		ValidOrNot = true;
		return true;

	case THAILAND:
		if (WifiBundle == 3){
			setLegalFields();
			ValidOrNot = false;
			return false;
		}
		ValidOrNot = true;
		return true;

	case INDIA:
		if (WifiBundle == 3){
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
