#ifndef LAB_STRING__ERRORS_H_
#define LAB_STRING__ERRORS_H_
#include <cstring>

class Error {
    public:
        Error(const char* message);
        char* getMessage() { return mess; }
    private:
        char* mess;
};

#endif //LAB_STRING__ERRORS_H_
