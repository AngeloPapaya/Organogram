#pragma once

#include "OrganogramPersonalInfo.h"


class CompanySort
{

public:
    std::vector<PersonalInfo::PersonalInfoIndex> sortedCompany (const std::vector<PersonalInfo::PersonalInfoIndex> &companiesInfo, PersonalInfo::PersonalInfoIndex &root);
    void sortByIDlinked(std::vector<PersonalInfo::PersonalInfoIndex>& object);
    void sortByID(std::vector<PersonalInfo::PersonalInfoIndex>& object);
};

