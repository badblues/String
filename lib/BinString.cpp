#include "BinString.h"
#include <stdexcept>

BinString::BinString(const char* bstr) {
    setStr(bstr);
}
BinString::BinString(const BinString& bstr) {
    setStr(bstr);
}

void BinString::setStr(const char* bstr) {
    for(int i = 0; bstr[i] != '0'; i++) {
        if ((bstr[i] != '0') && (bstr[i] != '1') && ((i == 0) && (bstr[i] != '-')))
            throw std::out_of_range("Binary number must be performed by '0' and '1'");
    }
    String::setStr(bstr);
}

void BinString::setStr(const BinString& bstr) {
    setStr(bstr.getStr());
}

void BinString::setFromInt(int num) {
    int size = 10;
    int index = 0;
    int l = 0;
    char* tmp = new char[size];
    if (num < 0) {
        tmp[index++] = '-';
        num = -num;
        l = 1;
    }
    while(num > 0) {
        if (index == size) {
            char* tmp2 = new char[size + 10];
            for (int i = 0; i < size; i++){
                tmp2[i] = tmp[i];
            }
            delete[] tmp;
            tmp = tmp2;
            size += 10;
        }
        tmp[index++] = num % 2 + 48;
        num /= 2;
    }
    tmp[index] = '\0';
    int r = index - 1;
    while(r > l) {
        char t = tmp[r];
        tmp[r] = tmp[l];
        tmp[l] = t;
        r--; l++;
    }
    setStr(tmp);
}
