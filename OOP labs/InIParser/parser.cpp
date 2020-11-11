#include <fstream>
#include <map>
#include <string>
#include <regex>
#include "exceptions.hpp"
#include "parser.hpp"

IniParser::IniParser(std::string filepath) {
  file.open(filepath);
  if (!file.is_open())
    throw FileNotFound("File not found\n");
}

void IniParser::Parse() {
  std::regex section_name_pattern("(\\[)([\\w]+)(\\])");
  std::regex key_value_pattern("([\\w]+)"
                               "([\\s]?=[\\s]?)"
                               "([\\w\\/\\.]+)"
                               "([\\s]?;?[\\s]?.*)");
  
  std::regex comment_pattern("([\\s]*)(;+)(.*)");
  std::regex space_pattern("([\\s*])");
  
  std::string str;
  std::cmatch matches;
  std::string section, key, value;
  
  while (!file.eof()) {
    std::getline(file, str);
    
    if (std::regex_match(str.c_str(), matches, section_name_pattern)) {
      section = matches[2];
    } else if (std::regex_match(str.c_str(), matches, key_value_pattern)) {
      key = matches[1];
      value = matches[3];
      
      Dictionary.insert(std::make_pair(section, std::make_pair(key, value)));
    }
    else if (!is_space(str) && !std::regex_match(str.c_str(), matches, comment_pattern)) {
      throw IncorrectFormatException("Incorrect format of file\n");
    }
  }
}


std::string IniParser::TryGetValue(std::string Section, std::string Key) {
  auto eq = Dictionary.equal_range(Section);
  
  if (eq.first == eq.second)
    throw SectionNotFoundException("Section not found\n");
  
  for (auto i = eq.first; i != eq.second; ++i) {
    if (i->second.first == Key)
      return i->second.second;
  }
  throw KeyNotFoundException("Key not found\n");
}


int IniParser::TryGetInt(std::string Section, std::string Key) {
  std::string val = TryGetValue(Section, Key);
  int result;
  
  try {
    result = std::stoi(val);
  }
  catch (const std::invalid_argument& ex) {
    throw InvalidConversionException("Invalid conversion to int\n");
  }
  return result;
}


double IniParser::TryGetDouble(std::string Section, std::string Key) {
  std::string val = TryGetValue(Section, Key);
  double result;
  
  try {
    result = std::stod(val);
  }
  catch (std::invalid_argument& ex) {
    throw InvalidConversionException("Invalid converion to float\n");
  }
  return result;
}


bool IniParser::is_space(std::string s) {
  for (auto i = s.cbegin(); i != s.cend(); ++i)
    if (*i != ' ' && *i != '\t')
      return false;
  return true;
}

IniParser::~IniParser() {
  file.close();
}
