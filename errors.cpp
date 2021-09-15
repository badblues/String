#include "errors.h"
#include <iostream>

using namespace std;

Error::Error(const char *message) {
    int size = 0;
    while(message[size] != '\0') size++;
    mess = new char[size];
    for (int i = 0; i <= size; i++) {
        mess[i] = message[i];
    }
    cout << "Error occurred: " << mess;
}
