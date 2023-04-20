#pragma once


enum DESTENATIONS {ROME, PRAGUE, NEWYORK, INDIA, THAILAND};

class BaseComparison {
public:
	BaseComparison() = default;
	bool virtual Validate() = 0;
	void virtual setLegalFields() = 0;
	bool virtual PrintValidationError(std::ostream&) = 0;
private:

};