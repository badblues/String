#include "NoteString.h"
#include <iostream>
#include <strstream>

NoteString::NoteString() {
    tm date;
    beg_ = date;
    end_ = date;
    flag_ = false;
}
NoteString::NoteString(const char *msg, tm beg, tm end) {
    String::setStr(msg);
    this->beg_ = beg;
    this->end_ = end;
    flag_ = false;
}
NoteString::NoteString(const char *msg, tm beg, tm end, bool flag) {
    String::setStr(msg);
    this->beg_ = beg;
    this->end_ = end;
    flag_ = flag;
}
NoteString::NoteString(const NoteString &note) {
    String::setStr(note.getStr());
    beg_ = note.beg_;
    end_ = note.end_;
    flag_ = note.flag_;
}

void NoteString::setBeginning(tm beg) {
    this->beg_ = beg;
}

void NoteString::setEnd(tm end) {
    this->end_ = end;
}

void NoteString::setFlag(bool flag) {
    flag_ = flag;
}

const char *NoteString::toStr() {
    strstream ss;
    ss << getStr() << ": " << beg_.tm_mday << "." << beg_.tm_mon << "." << beg_.tm_year << " - "
       << end_.tm_mday << "." << end_.tm_mon << "." << end_.tm_year << " Completion - " << flag_ << '\0';
    return ss.str();
}
