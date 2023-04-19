#pragma once
#include "Field.h"
#include "BaseComparison.h"
#include <vector>


const std::string bar = "-------------------------------------------------------------------------\n";


class Form {
private:
	std::vector<BaseField* > m_FieldsVector;
	std::vector<BaseComparison*> m_ValidatorVector;
public:
	Form() = default;
	int size() const;
	int sizeValidator() const;
	BaseField* GetField(int) const;
	BaseComparison* GetValidator(int) const;
	void addField(BaseField*);
	void addValidator(BaseComparison*);
	void fillForm();
	bool validateForm();
};

std::ostream& operator<<(std::ostream& os, Form obj);
