#include "OrganogramCompanySorter.h"
#include <algorithm>
#include <iostream>

std::vector<PersonalInfo::PersonalInfoIndex> CompanySort::createLeaveForRoot(const std::vector<PersonalInfo::PersonalInfoIndex> &companiesInfo, PersonalInfo::PersonalInfoIndex &root)
{

std::vector<PersonalInfo::PersonalInfoIndex> leaves;
    for (const auto& per: companiesInfo)
    {
        if (per.parentid == root.id)
        {
            leaves.push_back(per);
        }
    }
    return leaves;

}

void CompanySort::sortByIDlinked(std::vector<PersonalInfo::PersonalInfoIndex>& object)

{
    std::sort(object.begin(), object.end(), [](const PersonalInfo::PersonalInfoIndex &a, const PersonalInfo::PersonalInfoIndex &b)
    {
        return a.parentid < b.parentid;
    });

}

void CompanySort::sortByID(std::vector<PersonalInfo::PersonalInfoIndex>& object)

{
    std::sort(object.begin(), object.end(), [](const PersonalInfo::PersonalInfoIndex &a, const PersonalInfo::PersonalInfoIndex &b)
    {
        return a.id< b.id;
    });

}

void CompanySort::sortHierarchy(const std::vector<std::vector<std::string>>&res, const std::set<std::string>&companiesNames)

{
    DisplayHierarchy displayhierarchy;
    for (auto companiesnamesiterator = companiesNames.begin(); companiesnamesiterator != companiesNames.end(); ++companiesnamesiterator) //iteration for each company
    {
        int level =0;//setting hierarchy using spaces

        PersonalInfo personalinfoindex;
        auto companiesInfoo = personalinfoindex.createPersonalInfoIndexVector(res, *companiesnamesiterator);

        sortByIDlinked(companiesInfoo);

        PersonalInfo::PersonalInfoIndex root = companiesInfoo[0];

        std::cout <<*companiesnamesiterator << "\n" << root.id << " " << root.parentid << " " << root.name << " " << root.lastname << "\n";
        displayhierarchy.displayHierarchy(companiesInfoo);


    }


}

