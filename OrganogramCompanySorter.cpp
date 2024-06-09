#include "OrganogramCompanySorter.h"

//this function creates 'leave' vector per company
std::vector<PersonalInfo::PersonalInfoIndex> PrintSorted::createLeaveForRoot(const std::vector<PersonalInfo::PersonalInfoIndex> &companiesInfo, const PersonalInfo::PersonalInfoIndex &root)
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

void PrintSorted::sortByParentID(std::vector<PersonalInfo::PersonalInfoIndex>& object) //this function sorts vector by parentid
{
    std::sort(object.begin(), object.end(), [](const PersonalInfo::PersonalInfoIndex &a, const PersonalInfo::PersonalInfoIndex &b)
    {
        return a.parentid < b.parentid;
    });

}

void PrintSorted::sortByID(std::vector<PersonalInfo::PersonalInfoIndex>& object) //this function sorts vector by id
{
    std::sort(object.begin(), object.end(), [](const PersonalInfo::PersonalInfoIndex &a, const PersonalInfo::PersonalInfoIndex &b)
    {
        return a.id< b.id;
    });

}

void PrintSorted::PrintsortedHierarchy(const std::vector<std::vector<std::string>>&res, const std::set<std::string>&companiesNames) //final function which shows hierarchy for each company
{

    for (auto companiesnamesiterator = companiesNames.begin(); companiesnamesiterator != companiesNames.end(); ++companiesnamesiterator) //iteration for each company
    {
        int level =0;//setting hierarchy using spaces

        PersonalInfo personalinfoindex;
        auto companiesInfo = personalinfoindex.createPersonalInfoIndexVector(res, *companiesnamesiterator);

        sortByParentID(companiesInfo);

        PersonalInfo::PersonalInfoIndex root = companiesInfo[0];

        std::cout << *companiesnamesiterator << "\n" << root.name << root.lastname << ", " << root.company << ", " << root.position << "\n";
        DisplayHierarchy displayhierarchy;
        displayhierarchy.displayHierarchy(companiesInfo);

    }

}

