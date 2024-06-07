#pragma once

#include "OrganogramDisplay.h"
#include "OrganogramPersonalInfo.h"



class CompanySort
{

public:
//    CompanySort companysort;
    std::vector<PersonalInfo::PersonalInfoIndex> createLeaveForRoot (const std::vector<PersonalInfo::PersonalInfoIndex> &companiesInfo, PersonalInfo::PersonalInfoIndex &root);
    void sortByIDlinked(std::vector<PersonalInfo::PersonalInfoIndex>& object);
    void sortByID(std::vector<PersonalInfo::PersonalInfoIndex>& object);
    void sortHierarchy(const std::vector<std::vector<std::string>>&res, const std::set<std::string>&companiesNames);
};




