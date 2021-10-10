#include <iostream>
#include "lib/String.h"

int main() {
    String str1("qwerty");
    String str2("wer");
    String res = str1 + str2;
    String res2 = res + "kek";

    String res3 = res2 + "111";


    return 0;
}