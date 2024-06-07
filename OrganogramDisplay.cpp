#include "OrganogramDisplay.h"
#include "OrganogramPersonalInfo.h"


void DisplayHierarchy::displayHierarchy(const std::vector<PersonalInfo::PersonalInfoIndex> &companiesInfo )
{

    for (auto i = 0; i < companiesInfo.size(); ++i)
    {
        for (auto k =0; k < level; ++k)
        {
            std::cout << " ";
        }
        if (companiesInfo[i].idlinked != companiesInfo[i+1].idlinked && i < companiesInfo.size() - 1)
        {
                level++;
        }

        std::cout << (i == 0 ? "" : "->") << companiesInfo[i].id << " " << companiesInfo[i].idlinked <<  " " <<companiesInfo[i].name << " " <<
                        companiesInfo[i].lastname << " " << companiesInfo[i].position << "\n";

    }
    //std::cout << "\n\n";


}
