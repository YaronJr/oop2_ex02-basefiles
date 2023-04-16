#include "BaseNames.h"


std::string BaseNames::GetValues()
{
	std::string temp;
	temp += "(";
	for (int i = 0; i < m_Names.size(); i++) {
		temp += std::to_string(i + 1);
		temp += "-";
		temp += m_Names[i];
		if (i + 1 != m_Names.size())
			temp += ", ";
	}
	temp += ")";
	return temp;
}