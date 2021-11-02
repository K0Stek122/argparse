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
  for (int i = 0; i < argc - 1; i++)
  {
    char* curChar = argv[i];
    if (curChar[0] == '-' && IsArgumentCorrect(argToParse, curChar))
    {
      std::pair<std::string, std::string> temp;
      // temp.first = std::string(1, curChar[0]) + curChar[1];
      temp.first = FindFirstArgument(argToParse, curChar);
      temp.second = argv[i + 1];
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
