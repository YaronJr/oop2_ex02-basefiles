#include "Form.h"



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