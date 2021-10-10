#pragma once

//TODO "copy constructor must pass it's first argument with &"
//TODO 1 - (2 - 3) - (2 - 3) - 6 - 8
//TODO refactor exceptions

class String {
    public:
        String();
        String(const char *str);
        String(const String& str);
        String(const char *str, int pos, int len);
        String(const String &str, int pos, int len);
        ~String();
        String& operator = (String str2);
        friend String operator + (const String &str1, const String &str2);
        friend String operator + (const String &str1, const char* str2);
        friend String operator - (const String &str1, String &str2);
        friend String operator - (const String &str1, const char* str2);
        char& operator [] (unsigned int i);
        void setStr(const char *str);
        void setStr(const String &str);
        void setStr(const char *str, int pos, int len);
        void setStr(const String &str, int pos, int len);
        void catStr(const char *str);
        void catStr(const String &str);
        char *findStr(const char *str);
        char *findStr(const String &str);
        char *getStr() { return str_; };
        int getCapacity() { return capacity_; };
        int getSize() { return size_; };
        static int getNumberOfObjects() { return number_of_objects_; }
    private:
        static int number_of_objects_;
        char *str_;
        int capacity_;
        int size_;
};
