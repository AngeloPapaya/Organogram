#include "OrganogramLinesProviderFromFile.h"


std::vector<std::vector<std::string>> OrganogramLinesProviderFromFile::getOrganogramLines() //creating big vector and small vector per line)
{
    std::ifstream file(_fileName);
    std::vector <std::vector<std::string>> results; //big vector which contains all rows

            if (!file.is_open())
            {
                    std::cerr << "Nie udalo sie otworzyc pliku.\n";
                    return results;
            }

            while (std::getline(file,line))
            {
                std::vector <std::string> wordVector;//separate vector for each row, each time creating new vector for row
                std::string word;
                std::istringstream iss(line); // This line of code creates a std::istringstream input stream object named iss which
                                                                                    //is used to process text data from line

                while (std::getline(iss,word,',')) //here we divide the string of characters using a comma separator and save the data in 'word'
                {
                    if (!word.empty())
                        wordVector.push_back(word);//adding word to wordVector for each row
                }
                results.push_back(wordVector);//adding new row to big vector

            }

return results;
file.close();
}
