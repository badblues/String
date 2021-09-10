#ifndef LAB_STRING_STRING_H
#define LAB_STRING_STRING_H

class String {
public:
    String();
    String(char* str);
    void setString(char* str);
    void catStr(char* str);
    char* findStr(char* str);
    char* getStr() { return str_; };
    int  getMaxSize() { return max_size_; };
    int getSize() { return size_; };
private:
    char* str_;
    int max_size_;
    int size_;
};

#endif //LAB_STRING_STRING_H
