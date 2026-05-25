#ifndef ERROR
#define ERROR
#include <iostream>
#include <string>

class Error {  
    protected:
        std::string msg;  
    public:
        Error();
        Error(std::string);
        virtual void what() = 0;
        
};

class IndexError : public Error {
    public:
        IndexError();
        IndexError(std::string);
        virtual void what();
};

class IndexError1 : public IndexError {
    public:
        IndexError1();
        virtual void what();
};

class IndexError2 : public IndexError {
    public:
        IndexError2();
        virtual void what();
};

class SizeError : public Error {
    public:
        SizeError();
        SizeError(std::string);
        virtual void what();
};

class MaxSizeError : public SizeError {
    public:
        MaxSizeError();
        virtual void what();
};  

#endif