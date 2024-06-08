#pragma once

#include <vector>
#include <iostream>
#include "OrganogramCompanySorter.h"
#include "OrganogramPersonalInfo.h"


class DisplayHierarchy
{

public:
    PersonalInfo::PersonalInfoIndex root;
    int level =0;
    void displayHierarchy(const std::vector<PersonalInfo::PersonalInfoIndex> &companiesInfo );
};

