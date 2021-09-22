#include <iostream>
#include "string.h"
#include "errors.h"

int main() {
    String a;
    std::cout << "a: " << a.getStr() << "\n";
    String c = a + "kek";
    std::cout << "c: " << c.getStr() << "\n";
    return 0;
}