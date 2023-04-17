#include "Form.h"
#include <vector>



void Form::addField(BaseField* ptr) {
	m_FieldsVector.push_back(ptr);
}


void Form::addValidator(BaseComparison* ptr) {
	m_ValidatorVector.push_back(ptr);
}

void Form::fillForm() {
	for (auto & field : m_FieldsVector) {
		field->readData();
	}
}

bool Form::validateForm()
{
	for (auto& obj : m_FieldsVector){
		if (!obj->getIsGood()) {
			return false;
		}
	}
	return true;
}
