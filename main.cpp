#include <iostream>
#include <fstream>
#include "lib/String.h"
#include "lib/BinString.h"
#include "lib/NoteString.h"
#include "lib/Stack.h"
#include "lib/UniversalStack.h"
#include <cstdio>


int main(int argc, char** argv) {
    int* p;
    sscanf("1234567890123456", "%p", &p);
    printf("%p", p);
    return 0;
}