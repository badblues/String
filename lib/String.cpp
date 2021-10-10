#include <iostream>
#include <exception>
#include "String.h"

int String::number_of_objects_ = 0;

String::String() {
    std::cout << __FUNCTION__  << std::endl;
    setStr("");
    number_of_objects_++;
}

String::String(const char *str) {
    std::cout << __FUNCTION__  << std::endl;
    if (str == nullptr)
        throw std::logic_error("Can't write nullptr");
    this->setStr(str);
    number_of_objects_++;
}

String::String(const String& str) {
    std::cout << __FUNCTION__  << std::endl;
    this->setStr(str);
    number_of_objects_++;
}

String::String(const char *str, int pos, int len) {
    if (str == nullptr)
        throw std::logic_error("Can't write nullptr");
    this->setStr(str, pos, len);
    number_of_objects_++;
}

String::String(const String &str, int pos, int len) {
    this->setStr(str, pos, len);
    number_of_objects_++;
}

String::~String() {
    std::cout << __FUNCTION__  << std::endl;
    number_of_objects_--;
    delete[] str_;
}

String& String::operator = (String str2) {
    this->setStr(str2.str_);
    return *this;
}

String operator + (const String &str1, const String &str2) {
    String result(str1);
    result.catStr(str2);
    return result;
}

String operator + (const String &str1, const char* str2) {
    String result(str1);
    result.catStr(str2);
    return result;
}

String operator - (const String &str1, String &str2) {
    String result(str1);
    char* tmp = result.findStr(str2);
    if (tmp != nullptr) {
        while(*(tmp - 1) != '\0') {
            *tmp = *(tmp + str2.getSize());
            tmp++;
        }
    }
    return result;
}

String operator - (const String &str1, const char* str2) {
    String result(str1);
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
    if ((i >= size_) && (i < 0)) {
        throw std::logic_error("n/a index");
    }
    return str_[i];
}

void String::setStr(const String &str) {
    size_ = 0;
    while (str.str_[size_] != '\0') size_++;
    capacity_ = size_;
    delete[] str_;
    str_ = new char[capacity_];
    for (int i = 0; i <= size_; i++)
        str_[i] = str.str_[i];
}

void String::setStr(const char *str) {
    if (str == nullptr)
        throw std::logic_error("Can't write nullptr");
    size_ = 0;
    while (str[size_] != '\0') size_++;
    capacity_ = size_;
    delete[] str_;
    str_ = new char[capacity_];
    for (int i = 0; i <= size_; i++)
        str_[i] = str[i];
}

void String::setStr(const char *str, int pos, int len) {
    if (str == nullptr)
        throw std::logic_error("Can't write nullptr");
    size_ = 0;
    int size = 0;
    while(str[size] != 0) size++;
    if ((pos >= size) && (pos < 0))
        throw std::length_error("n/a index");
    while ((str[size_ + pos] != '\0') && (size_ < len)) size_++;
    capacity_ = size_;
    delete[] str_;
    str_ = new char[capacity_];
    for (int i = 0; i <= size_; i++)
        str_[i] = str[i + pos];
    str_[size_] = '\0';
}

void String::setStr(const String &str, int pos, int len) {
    size_ = 0;
    int size = 0;
    while(str.str_[size] != 0) size++;
    if ((pos >= size) && (pos < 0))
        throw std::length_error("n/a index");
    while ((str.str_[size_ + pos] != '\0') && (size_ < len)) size_++;
    capacity_ = size_;
    delete[] str_;
    str_ = new char[capacity_];
    for (int i = 0; i <= size_; i++)
        str_[i] = str.str_[i + pos];
    str_[size_] = '\0';
}

void String::catStr(const char *str) {
    if (str == nullptr)
        throw std::logic_error("Can't add nullptr");
    int size = 0;
    while (str[size] != '\0') size++;
    if (capacity_ == 0) {
        capacity_ = 1;
    }
    while (size_ + size > capacity_)
        capacity_ *= 2;
    char *tmp = new char[capacity_];
    for (int i = 0; i <= size_; i++)
        tmp[i] = str_[i];
    delete[] str_;
    str_ = tmp;
    for (int i = 0; i <= size; i++)
        str_[size_ + i] = str[i];
    size_ += size;
}

void String::catStr(const String &str) {
    int size = 0;
    while (str.str_[size] != '\0') size++;
    if (capacity_ == 0) {
        capacity_ = 1;
    }
    while (size_ + size > capacity_)
        capacity_ *= 2;
    char *tmp = new char[capacity_];
    for (int i = 0; i <= size_; i++)
        tmp[i] = str_[i];
    std::cout << str_ << std::endl << "addres:" << &str_ << std::endl;
    delete[] str_;
    str_ = tmp;
    for (int i = 0; i <= size; i++)
        str_[size_ + i] = str.str_[i];
    size_ += size;
}

char *String::findStr(const char *str) {
    if (str == nullptr)
        throw std::logic_error("Can't find nullptr");
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

char *String::findStr(const String &str) {
    char *ptr = nullptr;
    for (int i = 0; str_[i] != '\0'; i++)
        for (int j = 0; str.str_[j] != '\0'; j++) {
            if (str_[i + j] != str.str_[j])
                break;
            if (str.str_[j + 1] == '\0')
                ptr = &(str_[i]);
        }
    return ptr;
}