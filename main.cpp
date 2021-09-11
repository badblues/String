#include <iostream>
#include "string.h"

int main() {
    String kek("qwerty");
    std::cout << kek.getStr() << " len = " << kek.getSize() << std::endl;
    char b[10] = "r";
    std::cout << kek.findStr(b) << std::endl;
    kek.catStr("lol");
    std::cout << kek.getStr() << " len = " << kek.getSize() << std::endl;
    kek.setStr("aboba");
    std::cout << kek.getStr() << " len = " << kek.getSize() << std::endl;
}