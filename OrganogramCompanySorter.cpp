#include "OrganogramCompanySorter.h"
#include <algorithm>

std::vector<PersonalInfo::PersonalInfoIndex> CompanySort::sortedCompany (const std::vector<PersonalInfo::PersonalInfoIndex> &companiesInfo, PersonalInfo::PersonalInfoIndex &root)
{


std::vector<PersonalInfo::PersonalInfoIndex> leaves;
    for (const auto& per: companiesInfo) {
        if (per.idlinked == root.id) {
            leaves.push_back(per);
        }
    }
    return leaves;

}

