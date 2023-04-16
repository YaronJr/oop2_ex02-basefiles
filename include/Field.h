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
	BaseValidators* m_ValidatorPtr;
	T m_Data;
public:
	void readData() override;
	Field(std::string str) : m_Question(str) {};
	void addValidator(BaseValidators* ptr) { m_ValidatorPtr = ptr; };
};

template<class T>
void Field<T>::readData() {
	std::cout << m_Question << std::endl;
	std::cin >> m_Data;
}