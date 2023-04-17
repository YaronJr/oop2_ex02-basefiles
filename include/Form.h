#pragma once
#include "Field.h"
#include "BaseComparison.h"
#include <vector>

class Form {
private:
	std::vector<BaseField* > m_FieldsVector;
	std::vector<BaseComparison*> m_ValidatorVector;
public:
	Form() = default;
	void addField(BaseField*);
	void addValidator(BaseComparison*);
	void fillForm();
	bool validateForm();
};

