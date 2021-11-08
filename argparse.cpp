#include "argparse.h"

bool IsArgumentCorrect(std::vector<std::vector<std::string>> argToParse, char* curChar)
{
  for (int i = 0; i < argToParse.size(); i++)
  {
    if (std::find(argToParse[i].begin(), argToParse[i].end(), curChar) != argToParse[i].end())
    {
      return true;
    }
  }
  return false;
}

std::string FindFirstArgument(std::vector<std::vector<std::string>> argToParse, char* curChar)
{
  for (int i = 0; i < argToParse.size(); i++)
  {
    if (std::find(argToParse[i].begin(), argToParse[i].end(), curChar) != argToParse[i].end())
    {
      return argToParse[i][0];
    }
  }
  return std::string();
}

std::vector<std::pair<std::string, std::string>> argparse::parse(int argc, char* argv[], std::vector<std::vector<std::string>> argToParse)
{
  std::vector<std::pair<std::string, std::string>> out;
  for (int i = 0; i < argc; i++)
  {
    std::cout << "DEBUG: " << argv[i] << std::endl;
    char* curChar = argv[i];
    char* nextChar = argv[i + 1];
    if (curChar[0] == '-' && IsArgumentCorrect(argToParse, curChar))
    {
      std::cout << "DEBUG2: " << curChar << std::endl;
      std::cout << "DEBUG3: " << nextChar << std::endl;
      std::pair<std::string, std::string> temp;
      // temp.first = std::string(1, curChar[0]) + curChar[1];
      temp.first = FindFirstArgument(argToParse, curChar);
      if (nextChar[0] != '-')
      {
	temp.second = nextChar;
      }
      else if (nextChar[0] == '-')
      {
	temp.second = "TRUE";
      }
      out.push_back(temp);
    }
  }

  return out;
}

std::string argparse::find(std::vector<std::pair<std::string, std::string>> parsed, std::string argument)
{
  for (int i = 0; i < parsed.size(); i++)
  {
    if (parsed[i].first == argument)
      return parsed[i].second;
  }
  return std::string();
}
