#include "OrganogramDisplay.h"
#include "OrganogramPersonalInfo.h"


void DisplayHierarchy::displayHierarchy(const std::vector<std::string>&Signs, const std::vector<PersonalInfo::PersonalInfoIndex> &companiesInfoo )
{


std::vector<PersonalInfo::PersonalInfoIndex> companiesInfo = companiesInfoo ;
std::vector <std::string> Signss = Signs;
    for (auto i = 0; i < companiesInfoo.size(); ++i)
    {
        for (auto k =0; k < level; ++k)
        {
            std::cout << " ";
        }
        if (companiesInfoo[i].idlinked != companiesInfoo[i+1].idlinked && i < companiesInfoo.size() - 1)
        {
                level++;
        }

        std::cout << (i == 0 ? "" : Signs[i]) << companiesInfoo[i].id << " " << companiesInfoo[i].idlinked <<  " " <<companiesInfoo[i].name << " " <<
                        companiesInfoo[i].lastname << " " << companiesInfoo[i].position << "\n";

    }


}
