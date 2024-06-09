#include "OrganogramCompaniesName.h"

std::set<std::string> CompanyName::createSetofCompaniesNames(const std::vector <std::vector<std::string>>& res)//creating companiesNames set (string value)
{
    std::set<std::string> companiesNames;

    for (auto  j = 0; j < res.size(); j++)
    {
        companiesNames.insert(res[j][4]);
    }

    return companiesNames;
}


