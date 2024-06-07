#include "OrganogramLinesProviderFromFile.h"
#include "OrganogramPersonalInfo.h"
#include "OrganogramDisplay.h"
#include "OrganogramCompanySorter.h"

#include <vector>
#include <iostream>
#include <algorithm>
#include <set>


int main(int argc, char* argv[])

{
        OrganogramLinesProviderFromFile linesProvider("companies_data.csv");
        auto res = linesProvider.getOrganogramLines();


                                std::set<std::string> companiesNames;

                            for (auto  j = 0; j < res.size(); j++)
                            {

                                companiesNames.insert(res[j][4]);
                            }




for (auto companiesnamesiterator = companiesNames.begin(); companiesnamesiterator != companiesNames.end(); ++companiesnamesiterator)
{
int level =0;
PersonalInfo personalinfoindex;
std::vector<PersonalInfo::PersonalInfoIndex> companiesInfoo = personalinfoindex.createPersonalInfoIndexVector(res, *companiesnamesiterator);



std::sort(companiesInfoo.begin(), companiesInfoo.end(), [](const PersonalInfo::PersonalInfoIndex &a, const PersonalInfo::PersonalInfoIndex &b)
    {
        return a.idlinked < b.idlinked;
    });



 PersonalInfo::PersonalInfoIndex root = companiesInfoo[0];
CompanySort companysort;
std::cout << *companiesnamesiterator << "\n";
DisplayHierarchy displayhierarchy;

std::cout << root.id << " " << root.idlinked << " " << root.name << " " << root.lastname << "\n";
for (auto & i : companiesInfoo) {
        root = i;
        auto leaves = companysort.sortedCompany(companiesInfoo,root);

            std::sort(leaves.begin(), leaves.end(), [](const PersonalInfo::PersonalInfoIndex &a, const PersonalInfo::PersonalInfoIndex &b)
    {
        return a.id < b.id;
    });

        //std::cout<<"Root: "<<root.id<<" "<<root.idlinked<<" "<<root.name<<std::endl;
        for (auto j = 0; j < leaves.size(); ++j) {

                if (j == 0 || (leaves[j].idlinked != leaves[j-1].idlinked && j < leaves.size() - 1))
            {
                level++;

            }

            for (auto k =0; k < level ; ++k)
            {
                std::cout << " ";
            }

            std::cout << "->" << leaves[j].id << " " << leaves[j].idlinked << " " << leaves[j].name << " " << leaves[j].lastname << "\n";
        }


} std::cout << "\n";
    }
	return 0;

    }
