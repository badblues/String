#include "string.h"

String::String() {
    str_ = nullptr;
    max_size_ = 0;
    size_ = 0;
}

String::String(const char *str) {
    size_ = 0;
    while (str[size_] != '\0') size_++;
    max_size_ = size_;
    str_ = new char[max_size_];
    for (int i = 0; i <= size_; i++)
        str_[i] = str[i];
}

String& String::operator = (String& str2) {
    this->setStr(str2.getStr());
    return *this;
}

String String::operator + (const String& str2) {
    String result(this->str_);
    result.catStr(str2.str_);
    return result;
}

String String::operator + (const char* str2) {
    this->catStr(str2);
    return *this;
}

String String::operator - (const String& str2) {
    char* tmp = this->findStr(str2.str_);
    if (tmp != nullptr) {
        while(*(tmp - 1) != '\0') {
            *tmp = *(tmp + str2.size_);
            tmp++;
        }
    }
    return *this;
}

String String::operator - (const char* str2) {
    char* tmp = this->findStr(str2);
    if (tmp != nullptr) {
        int size = 0;
        while (str2[size] != '\0') size++;
        while(*(tmp - 1) != '\0') {
            *tmp = *(tmp + size);
            tmp++;
        }
    }
    return *this;
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
        throw (str_nullptr_error);
    size_ = 0;
    while (str[size_] != '\0') size_++;
    max_size_ = size_;
    str_ = new char[max_size_];
    for (int i = 0; i <= size_; i++)
        str_[i] = str[i];
}

void String::catStr(const char *str) {
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