#include "string.h"
#include <iostream>

int main() {
    String kek("qwerty");
    String lol("ert");
    kek = lol;
    std::cout << kek.getStr();
}