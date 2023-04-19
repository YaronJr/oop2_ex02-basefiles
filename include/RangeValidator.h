#pragma once
#include "BaseValidators.h"
#include <iostream>



template <class T>
class RangeValidator : public BaseValidators<T> {
public:
	std::string PrintError() override { return "Out of range"; }

	RangeValidator(int min, int max) : m_Min(min), m_Max(max) {};
	int GetMin() { return m_Min; }
	int GetMax() { return m_Max; }
	virtual bool IsValid(T obj) override { return (m_Max > obj && m_Min < obj); };
private:
	int m_Min, m_Max;

};


template <class T>
bool operator<(const int num, T  obj) {	return num-1 < obj.Get() ; }


template <class T>
bool operator>(const int num, T obj) { return num+1 > obj.Get(); }