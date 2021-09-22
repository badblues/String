#include <iostream>
#include "string.h"
#include "errors.h"

int main() {

    String str("qwerty");
    String a("Hello", 1, 2);
    std::cout << "a: " << a.getStr() << std::endl;
    String b(str, 3, 3);
    std::cout << "b: " << b.getStr() << std::endl;
    std::cout << String::getNumberOfObjects();
    return 0;
}