#pragma once
#include "String.h"

class BinString : public String {
    public:
        BinString() : String() {};
        BinString(const char* bstr);
        BinString(const BinString& bstr);
        virtual void setStr(const char* bstr);
        virtual void setStr(const BinString& bstr);
        void setFromInt(int num);
};
