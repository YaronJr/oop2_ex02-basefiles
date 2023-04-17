#pragma once


class BaseField {
public:
	BaseField() = default;
	void virtual readData() = 0;
	bool virtual getIsGood() = 0;
private:

};