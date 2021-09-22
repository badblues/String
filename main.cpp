#include <iostream>
#include "string.h"
#include "errors.h"

int main() {
    String a("kekovo");
    std::cout << a[4];
    a[4] = ' ';
    std::cout << " " << a.getStr();
}