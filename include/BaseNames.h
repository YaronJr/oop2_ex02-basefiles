#pragma once
#include <vector>
#include <string>
#include <iostream>






class BaseNames {
public:
	BaseNames() = default;
	std::string GetValues();
	std::istream& operator>>(std::istream& is)
	{
		is >> m_myData;
			return is;
	}
protected:
	std::vector<std::string> m_Names;
	int m_myData;
};

