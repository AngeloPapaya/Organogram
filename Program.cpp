#include "OrganogramLinesProviderFromFile.h"
#include "OrganogramPersonalInfo.h"
#include "MenuOption.h"
#include "OrganogramDisplay.h"
#include "OrganogramCompanySorter.h"

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
        auto res = linesProvider.getOrganogramLines();




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


CompanySort companysort;
std::vector<PersonalInfo::PersonalInfoIndex> sortedCompany = companysort.sortedCompany(companiesInfoo);
std::cout << companiesNames[z] << "\n";
DisplayHierarchy displayhierarchy;
displayhierarchy.displayHierarchy(Signs,sortedCompany);

}

	return 0;
}

