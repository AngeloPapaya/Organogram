#pragma once

#include "OrganogramDisplay.h"
#include "OrganogramPersonalInfo.h"
#include <algorithm>
#include <iostream>

class CompanySort
{

public:
    std::vector<PersonalInfo::PersonalInfoIndex> createLeaveForRoot (const std::vector<PersonalInfo::PersonalInfoIndex> &companiesInfo, const PersonalInfo::PersonalInfoIndex &root);
    void sortByParentID( std::vector<PersonalInfo::PersonalInfoIndex>& object);
    void sortByID( std::vector<PersonalInfo::PersonalInfoIndex>& object);
    void sortHierarchy(const std::vector<std::vector<std::string>>&res, const std::set<std::string>&companiesNames);
};




