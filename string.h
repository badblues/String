#ifndef LAB_STRING_STRING_H
#define LAB_STRING_STRING_H

class String {
    public:
        String();
        String(const char *str);
        ~String() {};
        String& operator = (String& str2);
        String operator + (const String& str2);
        String operator + (const char* str2);
        String operator - (const String& str2);
        String operator - (const char* str2);
        int& operator [] (unsigned int i);
        void setStr(const char *str);
        void catStr(const char *str);
        char *findStr(const char *str);
        char *getStr() { return str_; };
        int getMaxSize() { return max_size_; };
        int getSize() { return size_; };
    private:
        char *str_;
        int max_size_;
        int size_;
};

#endif //LAB_STRING_STRING_H
