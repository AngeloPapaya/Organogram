#include "OrganogramLinesProviderFromFile.h"
#include "OrganogramPersonalInfo.h"

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


std::string company;
int userInput;

std::cout << "Please choose company: " << "\n";

std::cout << "1. Oracle" << "\n" << "2. IBM" << "\n" << "3. Microsoft" << "\n";
std::cin >> userInput;

    switch (userInput)
    {
    case 1:
        company = "Oracle";
        break;
    case 2:
        company = "IBM";
        break;
    case 3:
        company = "Microsoft";
        break;
    }
    std::vector<PersonalInfo::PersonalInfoIndex> companiesInfoo;



for(auto i = 0; i < res.size(); ++i)
{
    if (res[i][4] == company)
    {
        PersonalInfo::PersonalInfoIndex p1;
        p1.id = std::stoi(res[i][0]);
        p1.idlinked = std::stoi(res[i][1]);
        p1.name = res[i][2];
        p1.lastname = res[i][3];
        p1.company = res[i][4];
        p1.city = res[i][5];
        p1.position = res[i][6];

        companiesInfoo.push_back(p1);
    }
}

for(int i=0;i<companiesInfoo.size();i++) { //petla zewnetrzna, sorting by hierarchy
    for(int j=1;j<companiesInfoo.size()-i;j++) { //pętla wewnętrzna
        if (companiesInfoo[j-1].idlinked == companiesInfoo[j].idlinked && companiesInfoo[j-1].id>companiesInfoo[j].id) {
            std::swap(companiesInfoo[j-1], companiesInfoo[j]);
        } else if(companiesInfoo[j-1].idlinked>companiesInfoo[j].idlinked) {
            std::swap(companiesInfoo[j-1], companiesInfoo[j]);
        }
    }
}


std::vector<std::string> Signs= {"->"};
    for (auto j = 0; j < companiesInfoo.size(); ++j)
            Signs.push_back(Signs[j]);




 int level = 0;
        for (auto i = 0; i < companiesInfoo.size(); ++i)
        {
            if (companiesInfoo[i].idlinked == companiesInfoo[i+1].idlinked)
            {


                for (auto k =0; k <= level; ++k)
                    {
                        std::cout << " ";
                    }
//                    level++;
            }
            else if (i!=0) {
                if (companiesInfoo[i-1].idlinked == companiesInfoo[i].idlinked) {
                        for (auto k =0; k <= level; ++k)
                    {
                        std::cout << " ";
                    }
                    level++;
                    std::cout << Signs[i] << companiesInfoo[i].id << " " << companiesInfoo[i].idlinked << " " << companiesInfoo[i].name << " " <<
                    companiesInfoo[i].lastname << " " << companiesInfoo[i].position << "\n";
                    continue;
                     level++;
                }
            }

            else
{
    //level++;
}
            std::cout << Signs[i] << companiesInfoo[i].id << " " << companiesInfoo[i].idlinked << " " << companiesInfoo[i].name << " " <<
                    companiesInfoo[i].lastname << " " << companiesInfoo[i].position << "\n";

}






	return 0;
}
