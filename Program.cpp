#include "OrganogramLinesProviderFromFile.h"
#include "OrganogramPersonalInfo.h"
#include "OrganogramDisplay.h"
#include "OrganogramCompanySorter.h"
#include "OrganogramCompaniesName.h"


int main(int argc, char* argv[])

{
    OrganogramLinesProviderFromFile linesProvider("companies_data.csv");
    auto res = linesProvider.getOrganogramLines();

    CompanyName companyname;
    PrintSorted printsorted;

    auto companiesNames = companyname.createSetofCompaniesNames(res);

    printsorted.PrintsortedHierarchy(res, companiesNames);

return 0;

}
