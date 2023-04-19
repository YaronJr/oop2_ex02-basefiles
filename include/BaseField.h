#pragma once


class BaseField {
public:
	BaseField() = default;
	void virtual readData() = 0;
	bool virtual getIsGood() = 0;
	void virtual printValue(std::ostream&) = 0;
	void virtual setGood() = 0;
private:

};