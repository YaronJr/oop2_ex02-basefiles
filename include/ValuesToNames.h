#pragma once
#include "Field.h"



template <class T> 
class ValuesToNames {
public:
	ValuesToNames() = default;
	std::string valuesAndNames();
	std::istream& operator>>(std::istream&, ValuesToNames&);
	
private:
	int m_data;
	T m_myT;
};

template <class T>
std::string ValuesToNames<T>::valuesAndNames() {
	return m_myT.GetValues();
}

template <class T>
std::istream& operator>>(std::istream& is, ValuesToNames& obj) {
	int value;
	is >> value;

}
