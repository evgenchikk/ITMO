#include <iostream>
#include <string>
#include "exceptions.hpp"
#include "parser.hpp"

int main(int argc, char* argv[]) {
  try {
//    std::string filepath = argv[0];
    std::string section = argv[1];
    std::string key = argv[2];
    std::string type = argv[3];

//    IniParser Parser(filepath);
    IniParser Parser("/Users/Evgeny/Documents/ITMO/Программирование/ООП/1/1/file.ini");
    Parser.Parse();
  
    if (type == "int") {
      std::cout << Parser.TryGetInt(section, key) << "\n";
    } else if (type == "float" || type == "double") {
      std::cout << Parser.TryGetDouble(section, key) << "\n";
    } else if (type == "string") {
      std::cout << Parser.TryGetValue(section, key) << "\n";
    }
  }
  catch (FileNotFound& ex) {
    std::cout << ex.what();
  }
  catch (IncorrectFormatException& ex) {
    std::cout << ex.what();
  }
  catch (SectionNotFoundException& ex) {
    std::cout << ex.what();
  }
  catch (KeyNotFoundException& ex) {
    std::cout << ex.what();
  }
  catch (InvalidConversionException& ex) {
    std::cout << ex.what();
  }
  
  return 0;
}
