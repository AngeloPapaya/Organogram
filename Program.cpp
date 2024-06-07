#include "OrganogramLinesProviderFromFile.h"
#include "OrganogramPersonalInfo.h"
#include "OrganogramDisplay.h"
#include "OrganogramCompanySorter.h"
#include "OrganogramCompaniesName.h"

#include <vector>
#include <iostream>
#include <algorithm>
#include <set>


int main(int argc, char* argv[])

{
        OrganogramLinesProviderFromFile linesProvider("companies_data.csv");
        auto res = linesProvider.getOrganogramLines();

CompanyName companyname;
CompanySort companysort;
DisplayHierarchy displayhierarchy;
auto companiesNames = companyname.createSetofCompaniesNames(res);


for (auto companiesnamesiterator = companiesNames.begin(); companiesnamesiterator != companiesNames.end(); ++companiesnamesiterator) //iteration for each company
{
    int level =0;//setting hierarchy using spaces

    PersonalInfo personalinfoindex;
    auto companiesInfoo = personalinfoindex.createPersonalInfoIndexVector(res, *companiesnamesiterator);

    companysort.sortByIDlinked(companiesInfoo);

    PersonalInfo::PersonalInfoIndex root = companiesInfoo[0];

    std::cout <<*companiesnamesiterator << "\n" << root.id << " " << root.parentid << " " << root.name << " " << root.lastname << "\n";
    DisplayHierarchy displayhierarchy;
    displayhierarchy.displayHierarchy(companiesInfoo);


}
	return 0;

    }
