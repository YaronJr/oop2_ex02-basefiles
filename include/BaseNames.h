#pragma once
#include <vector>
#include <string>
#include <iostream>






class BaseNames {
public:
	BaseNames() = default;
	std::string GetValues();
	int getnum() { return m_myData; };
	
protected:
	std::vector<std::string> m_Names;
	int m_myData;
};

