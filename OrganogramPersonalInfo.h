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
    std::vector<PersonalInfo::PersonalInfoIndex> createPersonalInfoIndexVector(const std::vector<std::vector<std::string>>&res, const std::string& companyName);
};


