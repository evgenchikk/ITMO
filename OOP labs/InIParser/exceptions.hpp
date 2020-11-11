#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

class FileNotFound : public std::exception {
private:
  const char* error;
public:
  FileNotFound();
  FileNotFound(const char* error_)
  : error(error_)
  {}
  
  const char* what() const noexcept {
    return error;
  }
};

class IncorrectFormatException : public std::exception {
private:
  const char* error;
public:
  IncorrectFormatException();
  IncorrectFormatException(const char* error_)
  : error(error_)
  {}
  
  const char* what() const noexcept {
    return error;
  }
};

class SectionNotFoundException : public std::exception {
private:
  const char* error;
public:
  SectionNotFoundException();
  SectionNotFoundException(const char* error_)
  : error(error_)
  {}
  
  const char* what() const noexcept {
    return error;
  }
};

class KeyNotFoundException : public std::exception {
private:
  const char* error;
public:
  KeyNotFoundException();
  KeyNotFoundException(const char* error_)
  : error(error_)
  {}
  
  const char* what() const noexcept {
    return error;
  }
};

class InvalidConversionException : public std::exception {
private:
  const char* error;
public:
  InvalidConversionException();
  InvalidConversionException(const char* error_)
  : error(error_)
  {}
  
  const char* what() const noexcept {
    return error;
  }
};

#endif
