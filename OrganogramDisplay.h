#pragma once

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "OrganogramPersonalInfo.h"

class DisplayHierarchy
{

public:
    int level =0;
    void displayHierarchy(const std::vector<std::string>&Signs, const std::vector<PersonalInfo::PersonalInfoIndex> &companiesInfoo );
};
