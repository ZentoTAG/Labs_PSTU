#include <iostream>
#include "Error.h"

Error::Error() : msg("Error") {}
Error::Error(std::string m) : msg(m) {}

IndexError::IndexError() : Error("Index error") {}
IndexError::IndexError(std::string m) : Error(m) {}
void IndexError::what() {
    std::cout << msg << std::endl;
}

IndexError1::IndexError1() : IndexError("Error: index < 0") {}
void IndexError1::what() {
    std::cout << msg << std::endl;
}

IndexError2::IndexError2() : IndexError("Error: index >= size") {}
void IndexError2::what() {
    std::cout << msg << std::endl;
}

SizeError::SizeError() : Error("Size error") {}
SizeError::SizeError(std::string m) : Error(m) {}
void SizeError::what() {
    std::cout << msg << std::endl;
}

MaxSizeError::MaxSizeError() : SizeError("Error: size > MAX SIZE") {}
void MaxSizeError::what() {
    std::cout << msg << std::endl;
}