#include "string.h"
#include <cstdlib>

//TODO replace malloc/realloc with new

String::String() {
    str_ = nullptr;
    max_size_ = 0;
    size_ = 0;
}

String::String(char* str) {
    size_ = 0;
    while(str[size_] != '\0') size_++;
    max_size_ = size_;
    str_ = (char*) malloc(sizeof(max_size_));
    //TODO refactor this block
    for (int i = 0;; i++) {
        str_[i] = str[i];
        if (str[i] == '\0')
            break;
    }
}

void String::setString(char* str) {
    while(str[size_] != '\0') size_++;
    max_size_ = size_;
    str_ = (char*) malloc(max_size_);
    //TODO refactor this block
    for (int i = 0;; i++) {
        str_[i] = str[i];
        if (str[i] == '\0')
            break;
    }
}

void String::catStr(char* str) {
    int size = 0;
    while(str[size] != '\0') size++;
    size_ += size;
    while(size_ < max_size_)
        max_size_ *= 2;
    str_ = (char*) realloc(str_, max_size_);
    //TODO and this block
    for (int i = 0;; i++) {
        str_[size_ + i] = str[i];
        if (str[i] == '\0')
            break;
    }
}
//TODO ask Vlad to share his func fo this
char* String::findStr(char* str) {
    char* ptr  = nullptr;
    for (int i = 0; str_[i] != '\0'; i++)
        for (int j = 0; str[j] != '\0'; j++) {
            if (str_[i + j] != str[j])
                break;
            ptr = &(str_[i + j]);
        }
    return ptr;
}