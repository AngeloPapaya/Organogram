#pragma once

#include <vector>
#include <map>
#include <string>

class PersonalInfo
{
public:

    struct PersonalInfoIndex
    {
        int id;
        int idlinked;
        std::string name;
        std::string lastname;
        std::string company;
        std::string city;
        std::string position;
    };
    std::map<std::string, std::vector<PersonalInfoIndex>> companiesInfo;
};


