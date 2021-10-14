#include <iostream>
#include "lib/String.h"
#include "lib/BinString.h"
#include "lib/NoteString.h"

int main(int argc, char** argv) {
    NoteString note;
    note.setStr("make lab tasks");
    note.setBeginning(NoteString::toDate(1, 9, 2021));
    note.setEnd(NoteString::toDate(1, 12, 2021));
    note.setFlag(false);
    std::cout << note.toStr() << "\n";
    return 0;
}