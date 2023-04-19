#include "Form.h"
#include <vector>



int Form::size() const
{
	return m_FieldsVector.size();
}

int Form::sizeValidator() const{
	return m_ValidatorVector.size();
}

BaseField* Form::GetField(int num) const
{
	return m_FieldsVector[num];
}

BaseComparison* Form::GetValidator(int i) const{
	return m_ValidatorVector[i];
}

void Form::addField(BaseField* ptr) {
	m_FieldsVector.push_back(ptr);
}


void Form::addValidator(BaseComparison* ptr) {
	m_ValidatorVector.push_back(ptr);
}

void Form::fillForm() {
	for (auto & field : m_FieldsVector) {
		field->readData();}

}

bool Form::validateForm()
{
	for (auto& obj : m_FieldsVector){
		if (!obj->getIsGood()) {
			return false;
		}
	}

	for (auto& obj : m_ValidatorVector) {
		if (!obj->Validate())
			return false;
	}

	return true;
}

std::ostream& operator<<(std::ostream& os, Form obj) {
	for (int i = 0; i < obj.size(); i++) {
		BaseField* temp = obj.GetField(i);
		os << bar;
		temp->printValue(os);
		os << bar;
	}
	for (int i = 0; i < obj.sizeValidator(); i++) {
		if (!obj.GetValidator(i)->PrintValidationError(os)) {
			break;
		}
	}
	return os;
}
