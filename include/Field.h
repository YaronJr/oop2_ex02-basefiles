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
	bool m_isGood;
public:
	bool getIsGood() override { return m_isGood; } ;
	void readData() override;
	Field(std::string str) : m_Question(str), m_isGood(false) {};
	void addValidator(BaseValidators<T>* ptr) { m_ValidatorPtr = ptr; };
};

template<class T>
void Field<T>::readData() {
	if (!m_isGood) {

		std::cout << m_Question << std::endl;
		std::cin >> m_Data;
	}
	m_isGood = m_ValidatorPtr->IsValid(m_Data);
}