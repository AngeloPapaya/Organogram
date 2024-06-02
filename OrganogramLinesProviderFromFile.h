#pragma once

#include <string>
#include <vector>

class OrganogramLinesProviderFromFile

{
private:
        std::string _fileName;
public:

        explicit OrganogramLinesProviderFromFile(const std::string& fileName)
        {
            _fileName = fileName.c_str();

        }

    std::vector<std::vector<std::string>> GetOrganogramLines();

};
