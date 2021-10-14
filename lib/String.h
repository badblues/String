#pragma once
#include <istream>
#include <ostream>

using namespace std;

//TODO overload io operators

class String {
    public:
        String();
        String(const char * str);
        String(const String& str);
        String(const char *str, int pos, int len);
        String(const String &str, int pos, int len);
        ~String();
        void setStr(const char *str);
        void setStr(const String &str);
        void setStr(const char *str, int pos, int len);
        void setStr(const String &str, int pos, int len);
        void catStr(const char *str);
        void catStr(const String &str);
        char *findStr(const char *str);
        char *findStr(const String &str);
        char *getStr() const { return str_; };
        int getCapacity() { return capacity_; };
        int getSize() const { return size_; };
        //operators
        String& operator = (const String& str2);
        friend String operator + (const String &str1, const String &str2);
        friend String operator + (const String &str1, const char* str2);
        friend String operator - (const String &str1, const String &str2);
        friend String operator - (const String &str1, const char* str2);
        char& operator [] (unsigned int i);
        //io streams
        friend istream& operator >> (istream& is, String& str);
        friend ostream& operator << (ostream& os, String& str);
        //friend ifstream& operator >> (ifstream& ifs, String& str);
        //friend ofstream& operator << (ofstream& ofs, String& str);
        static int getNumberOfObjects() { return number_of_objects_; }
    private:
        static int number_of_objects_;
        char *str_;
        int capacity_;
        int size_;
};
