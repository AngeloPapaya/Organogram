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

void CompanySort::sortByIDlinked(std::vector<PersonalInfo::PersonalInfoIndex>& object)

{
    std::sort(object.begin(), object.end(), [](const PersonalInfo::PersonalInfoIndex &a, const PersonalInfo::PersonalInfoIndex &b)
    {
        return a.idlinked < b.idlinked;
    });

}

void CompanySort::sortByID(std::vector<PersonalInfo::PersonalInfoIndex>& object)

{
    std::sort(object.begin(), object.end(), [](const PersonalInfo::PersonalInfoIndex &a, const PersonalInfo::PersonalInfoIndex &b)
    {
        return a.id< b.id;
    });

}

