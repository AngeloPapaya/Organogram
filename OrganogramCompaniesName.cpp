
#include "OrganogramCompaniesName.h"

std::set<std::string> CompanyName::createSetofCompaniesNames(const std::vector <std::vector<std::string>>& res)
{
                            std::set<std::string> companiesNames;//creating companiesNames set (string value)

                            for (auto  j = 0; j < res.size(); j++)
                            {

                                companiesNames.insert(res[j][4]);
                            }

    return companiesNames;


}


