#pragma once

#include "OrganogramDisplay.h"
#include "OrganogramPersonalInfo.h"
#include <algorithm>
#include <iostream>

class PrintSorted
{

public:
    std::vector<PersonalInfo::PersonalInfoIndex> createLeaveForRoot (const std::vector<PersonalInfo::PersonalInfoIndex> &companiesInfo, const PersonalInfo::PersonalInfoIndex &root);
    void sortByParentID( std::vector<PersonalInfo::PersonalInfoIndex>& object);
    void sortByID( std::vector<PersonalInfo::PersonalInfoIndex>& object);
    void sortHierarchyAndPrint(const std::vector<std::vector<std::string>>&res, const std::set<std::string>&companiesNames);
};




