#include "OrganogramDisplay.h"
#include "OrganogramPersonalInfo.h"

void DisplayHierarchy::displayHierarchy(const std::vector<PersonalInfo::PersonalInfoIndex> &companiesInfo)
{
    PrintSorted printsorted;
    for (auto & i : companiesInfo)
    {
        root = i;
        auto leaves = printsorted.createLeaveForRoot(companiesInfo,root);
        printsorted.sortByID(leaves);

        for (auto j = 0; j < leaves.size(); ++j)
        {

                if (j == 0 || (leaves[j].parentid != leaves[j-1].parentid))
                {
                    levelOfDisplaying++;
                }

                for (auto k =0; k < levelOfDisplaying ; ++k)
                {
                    std::cout << " ";
                }
                std::cout << "-> " << leaves[j].name << " " << leaves[j].lastname << ", " << leaves[j].company << ", " << leaves[j].position << "\n";
        }

    }
    std::cout << "\n";
}
