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

auto companiesNames = companyname.createSetofCompaniesNames(res);

companysort.sortHierarchy(res, companiesNames);



return 0;

}
