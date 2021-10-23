#include <iostream>
#include <fstream>
#include "lib/String.h"
#include "lib/BinString.h"
#include "lib/NoteString.h"
#include "lib/Stack.h"

int main(int argc, char** argv) {
    String str("qwe");
    BinString bstr("101010");
    NoteString nstr;
    nstr.setStr("keke");
    Stack st(&nstr);
    st.push(&str);
    st.push(&bstr);
    st.begin();
    std::cout << st.getObj().getStr() << '\n';
    ++st;
    std::cout << st.getObj().getStr() << '\n';
    ++st;
    std::cout << st.getObj().getEnd().tm_mday << '\n';
    std::cout << st.getObj().getStr() << '\n';
}