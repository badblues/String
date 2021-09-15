#include <iostream>
#include "string.h"
#include "errors.h"

String::String(const char *str) {
    if (str == nullptr)
        throw Error("str is nullptr\n");
    this->setStr(str);
}

String::String(String const& str) {
    this->setStr(str.str_);
}

String& String::operator = (String str2) {
    this->setStr(str2.str_);
    return *this;
}

String operator + (String str1, String str2) {
    String result(str1.str_);
    result.catStr(str2.str_);
    return result;
}

String operator + (String str1, const char* str2) {
    String result(str1.str_);
    result.catStr(str2);
    return result;
}

String operator - (String str1, String str2) {
    String result(str1.str_);
    char* tmp = result.findStr(str2.str_);
    if (tmp != nullptr) {
        while(*(tmp - 1) != '\0') {
            *tmp = *(tmp + str2.size_);
            tmp++;
        }
    }
    return result;
}

String operator - (String str1, const char* str2) {
    String result(str1.str_);
    char* tmp = result.findStr(str2);
    if (tmp != nullptr) {
        int size = 0;
        while (str2[size] != '\0') size++;
        while(*(tmp - 1) != '\0') {
            *tmp = *(tmp + size);
            tmp++;
        }
    }
    return result;
}

//TODO add returning char*
int& String::operator [] (unsigned int i) {
    switch(i) {
        case 0:
            return size_;
        case 1:
            return max_size_;
        default:
            return size_;
    }
}

void String::setStr(const char *str) {
    if (str == nullptr)
        throw Error("str is nullptr\n");
    size_ = 0;
    while (str[size_] != '\0') size_++;
    max_size_ = size_;
    str_ = new char[max_size_];
    for (int i = 0; i <= size_; i++)
        str_[i] = str[i];
}

void String::catStr(const char *str) {
    if (str == nullptr)
        throw Error("str is nullptr\n");
    int size = 0;
    while (str[size] != '\0') size++;
    while (size_ + size > max_size_)
        max_size_ *= 2;
    char *tmp = new char[max_size_];
    for (int i = 0; i <= size_; i++)
        tmp[i] = str_[i];
    str_ = tmp;
    for (int i = 0; i <= size; i++)
        str_[size_ + i] = str[i];
    size_ += size;
}

char *String::findStr(const char *str) {
    if (str == nullptr)
        throw Error("str is nullptr\n");
    char *ptr = nullptr;
    for (int i = 0; str_[i] != '\0'; i++)
        for (int j = 0; str[j] != '\0'; j++) {
            if (str_[i + j] != str[j])
                break;
            if (str[j + 1] == '\0')
                ptr = &(str_[i]);
        }
    return ptr;
}