#pragma once
#include "BaseNames.h"


class DestinationNames : public BaseNames{
private:

public:
	DestinationNames();
};

DestinationNames::DestinationNames(){
	m_Names = std::vector<std::string>({ "Rome", "Prague", "New York", "India", "Thailand" });
}
