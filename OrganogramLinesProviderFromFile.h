#pragma once

#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>


class OrganogramLinesProviderFromFile
{
private:
        std::string _fileName;
        std::string line;

public:

        explicit OrganogramLinesProviderFromFile(const std::string& fileName)
        {
            _fileName = fileName.c_str();

        }

    std::vector<std::vector<std::string>> getOrganogramLines();
};
