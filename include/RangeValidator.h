#pragma once
#include "BaseValidators.h"

template <class T>
class RangeValidator : public BaseValidators<T> {
public:
	RangeValidator(int min, int max) : m_Min(min), m_Max(max) {};
	int GetMin() { return m_Min; }
	int GetMax() { return m_Max; }
	bool IsValid(T obj) override { return true; };//return (m_Max < obj && m_Min > obj); };
private:
	int m_Min, m_Max;

};


template <class T>
bool operator<(const int num, T  obj) { return obj.getnum() >  num; }


template <class T>
bool operator>(const int num, T obj) { return obj.getnum() < num; }