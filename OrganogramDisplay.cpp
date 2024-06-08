#include "OrganogramDisplay.h"
#include "OrganogramPersonalInfo.h"


void DisplayHierarchy::displayHierarchy(const std::vector<PersonalInfo::PersonalInfoIndex> &companiesInfo)
{
    CompanySort companysort;
    for (auto & i : companiesInfo)
    {
        root = i;
        auto leaves = companysort.createLeaveForRoot(companiesInfo,root);
        companysort.sortByID(leaves);

        for (auto j = 0; j < leaves.size(); ++j)
        {

                if (j == 0 || (leaves[j].parentid != leaves[j-1].parentid))
                {
                    level++;
                }

                for (auto k =0; k < level ; ++k)
                {
                    std::cout << " ";
                }
                std::cout << "->" << leaves[j].id << " " << leaves[j].parentid << " " << leaves[j].name << " " << leaves[j].lastname << "\n";
        }


    }
    std::cout << "\n";



}
