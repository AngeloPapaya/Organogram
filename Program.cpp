#include "OrganogramLinesProviderFromFile.h"
#include "OrganogramPersonalInfo.h"
#include "MenuOption.h"
#include "OrganogramDisplay.h"

#include <fstream>
#include <vector>
#include <iostream>
#include <array>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>



int main(int argc, char* argv[])
{
        OrganogramLinesProviderFromFile linesProvider("companies_data.csv");
        auto res = linesProvider.GetOrganogramLines();




                                std::vector<std::string> companiesNames;

                            for (auto  j = 0; j < res.size(); j++)
                            {

                                companiesNames.push_back(res[j][4]);
                            }

                            std::sort(companiesNames.begin(), companiesNames.end());
                            auto last = std::unique(companiesNames.begin(), companiesNames.end());
                            companiesNames.erase(last, companiesNames.end());





for (auto z = 0; z < companiesNames.size(); ++z)
{

PersonalInfo personalinfoindex;
std::vector<PersonalInfo::PersonalInfoIndex> companiesInfoo = personalinfoindex.createPersonalInfoIndexVector(res, companiesNames[z]);


std::vector<std::string> Signs;
    for (auto j = 0; j < companiesInfoo.size(); ++j)
            Signs.push_back("->");



for(int i = 0; i < companiesInfoo.size(); i++)
{
        for(int j = 1; j < companiesInfoo.size() - i; j++)
        {
            if (companiesInfoo[j-1].id != companiesInfoo[j].idlinked )
                if(companiesInfoo[j-1].idlinked != companiesInfoo[j].idlinked)
                    std::swap(companiesInfoo[j-1], companiesInfoo[j]);
        }
}


std::cout << companiesNames[z] << "\n";
DisplayHierarchy displayhierarchy;
displayhierarchy.displayHierarchy(Signs,companiesInfoo);
std::cout << "\n\n";

}

	return 0;
}

