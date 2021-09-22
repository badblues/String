#include <iostream>
#include "string.h"
#include "errors.h"

int String::number_of_objects_ = 0;

String::String() {
    setStr("");
    number_of_objects_++;
}

String::String(const char *str) {
    if (str == nullptr)
        throw Error("str is nullptr\n");
    this->setStr(str);
    number_of_objects_++;
}

String::String(String const& str) {
    this->setStr(str.str_);
    number_of_objects_++;
}

String::String(const char *str, int pos, int len) {
    this->setStr(str, pos, len);
    number_of_objects_++;
}

String::String(String &str, int pos, int len) {
    this->setStr(str.getStr(), pos, len);
    number_of_objects_++;
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

char& String::operator [] (unsigned int i) {
    if (i > size_) {
        throw Error("n/a index\n");
    }
    return str_[i];
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

void String::setStr(const char *str, int pos, int len) {
    if (str == nullptr)
        throw Error("str is nullptr\n");
    size_ = 0;
    int size = 0;
    while(str[size] != 0) size++;
    if (pos >= size)
        throw Error ("n/a index\n");
    while ((str[size_ + pos] != '\0') && (size_ < len)) size_++;
    max_size_ = size_;
    str_ = new char[max_size_];
    for (int i = 0; i <= size_; i++)
        str_[i] = str[i + pos];
    str_[size_] = '\0';
}

void String::catStr(const char *str) {
    if (str == nullptr)
        throw Error("str is nullptr\n");
    int size = 0;
    while (str[size] != '\0') size++;
    max_size_ = size_ + size;
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