#pragma once
#include "Field.h"





template <class T> 
class ValuesToNames {
public:
	ValuesToNames() = default;
	std::string valuesAndNames();
	void Set(int temp) { m_data = temp; }
	int Get() const;
private:
	int m_data;
	T m_myT;
};

template <class T>
std::string ValuesToNames<T>::valuesAndNames() {
	return m_myT.GetValues();
}

template<class T>
inline int ValuesToNames<T>::Get() const
{
	return m_data;
}


template <class T>
std::istream& operator>>(std::istream& is, ValuesToNames <T> &obj) {
	int value;
	is >> value;
	obj.Set(value);
	return is;
}


template <class T>
std::ostream& operator<<(std::ostream& os, ValuesToNames <T> obj) {
	os << obj.Get();
	return os;
}