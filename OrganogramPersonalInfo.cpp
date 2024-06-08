#include "OrganogramPersonalInfo.h"


std::vector<PersonalInfo::PersonalInfoIndex> PersonalInfo::createPersonalInfoIndexVector(const std::vector<std::vector<std::string>>&res, const std::string& companyName)
{
    std::vector<PersonalInfo::PersonalInfoIndex> companiesInfoo;

for (size_t i = 0; i < res.size(); ++i)
    {
            if (res[i][4] == companyName)
            {
                PersonalInfoIndex p1;
                p1.id = std::stoi(res[i][0]);
                p1.parentid = std::stoi(res[i][1]);
                p1.name = res[i][2];
                p1.lastname = res[i][3];
                p1.company = res[i][4];
                p1.city = res[i][5];
                p1.position = res[i][6];

                companiesInfoo.push_back(p1);
            }
        }


return companiesInfoo;

}
