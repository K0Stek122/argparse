#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

namespace argparse
{
  std::vector<std::pair<std::string, std::string>> parse(int argc, char* argv[], std::vector<std::vector<std::string>> argToParse);
  std::string find(std::vector<std::pair<std::string, std::string>> parsed, std::string argument);
}
