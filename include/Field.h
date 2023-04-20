#pragma once
#include <string>
#include <stdlib.h>
#include <iostream>
#include "BaseValidators.h"
#include "BaseField.h"
#include <vector>



template <class T> 
class Field : public BaseField{
private:
	std::string m_Question;
	BaseValidators<T> * m_ValidatorPtr;
	T m_Data;
	bool m_isGood, m_ErrorMessage;

public:
	void setGood(bool ValidOrNot) override { m_isGood = ValidOrNot; }
	void printValue(std::ostream&) override;
	bool getIsGood() override { return m_isGood; };
	void readData() override;

	T get() { return m_Data; }

	Field(std::string str) : m_Question(str), m_isGood(false) {};
	void addValidator(BaseValidators<T>* ptr) { m_ValidatorPtr = ptr; };
};

template<class T>
inline void Field<T>::printValue(std::ostream& os){
	os << m_Question << " = " << m_Data;
	if (!m_isGood) {
		os << "		";
		if (!m_ErrorMessage)
			os << m_ValidatorPtr->PrintError();
	}
	os << std::endl;

}

template<class T>
void Field<T>::readData() {
	if (!m_isGood) {

		std::cout << m_Question << std::endl;
		std::cin >> m_Data;
	}
	m_isGood = m_ErrorMessage =  m_ValidatorPtr->IsValid(m_Data);
	
}
