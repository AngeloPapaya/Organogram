#include "OrganogramCompanySorter.h"


std::vector<PersonalInfo::PersonalInfoIndex> CompanySort::sortedCompany (const std::vector<PersonalInfo::PersonalInfoIndex> &companiesInfo)
{
    std::vector<PersonalInfo::PersonalInfoIndex> companiesInfoo = companiesInfo;
    for(int i = 0; i < companiesInfoo.size(); i++)
{
        for(int j = 1; j < companiesInfoo.size() - i; j++)
        {
            if (companiesInfoo[j-1].id > companiesInfoo[j].idlinked)
            {
                std::swap(companiesInfoo[j-1], companiesInfoo[j]);
                if ((companiesInfoo[j-1].idlinked == companiesInfoo[j].idlinked && companiesInfoo[j-1].id > companiesInfoo[j].id))
                {
                    std::swap(companiesInfoo[j-1], companiesInfoo[j]);
                }

            }

        }
}
    return companiesInfoo;
}
