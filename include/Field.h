#pragma once
#include <string>
#include <stdlib.h>
#include <iostream>


template <class T> 
class Field {
protected:
	std::string m_Question;
	T m_Data;

public:
	Field(std::string);
};


template <class T>
Field<T>::Field(std::string str) {
	m_Question = str;
	std::cin >> m_Data;
}


