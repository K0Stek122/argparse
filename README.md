# argparse
C++ library for parsing command line arguments

## How to use
Just add argparse.h and argparse.cpp to your project and then include argparse.h wherever you need

## Example Usage:
```c++
int main(int argc, char* argv[])
{
  std::vector<std::vector<std::string>> argToParse = { { "-c", "--count" }, { "-p", "--patrick" }, { "-o", "--output" } };
  std::vector<std::pair<std::string, std::string>> parsed = argparse::parse(argc, argv, argToParse);
  for (int i = 0; i < parsed.size(); i++)
  {
    std::cout << parsed[i].first << " | " << parsed[i].second << std::endl;
  }

  std::cout << argparse::find(parsed, "-c") << std::endl;
  std::cout << argparse::find(parsed, "-p") << std::endl;
  std::cout << argparse::find(parsed, "-t") << std::endl;
}
```
