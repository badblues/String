#ifndef LAB_STRING_STRING_H
#define LAB_STRING_STRING_H

//TODO learn about destructors and deleting an class object
//TODO "copy constructor must pass it's first argument with &"
//TODO check leaks

class String {
    public:
        String();
        String(const char *str);
        String(String const& str);
        String(const char *str, int pos, int len);
        String(String &str, int pos, int len);
        ~String() { number_of_objects_--;};
        String& operator = (String str2);
        friend String operator + (String str1, String str2);
        friend String operator + (String str1, const char* str2);
        friend String operator - (String str1, String str2);
        friend String operator - (String str1, const char* str2);
        char& operator [] (unsigned int i);
        void setStr(const char *str);
        void setStr(const char *str, int pos, int len);
        void catStr(const char *str);
        char *findStr(const char *str);
        char *getStr() { return str_; };
        int getMaxSize() { return max_size_; };
        int getSize() { return size_; };
        static int getNumberOfObjects() { return number_of_objects_; }
    private:
        static int number_of_objects_;
        char *str_;
        int max_size_;
        int size_;
};

#endif //LAB_STRING_STRING_H
