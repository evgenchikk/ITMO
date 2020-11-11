#ifndef PARSER_HPP
#define PARSER_HPP

#include <map>
#include <string>
#include <fstream>

class IniParser {
public:
  IniParser(std::string filepath);
  
  void Parse();
  
  std::string TryGetValue(std::string Section, std::string Key);
  
  int TryGetInt(std::string Section, std::string Key);
  
  double TryGetDouble(std::string Section, std::string Key);
  
  bool is_space(std::string s);
  
  ~IniParser();
  
private:
  std::ifstream file;
  std::multimap<std::string, std::pair<std::string, std::string>> Dictionary;
};

#endif
