#include "NoteString.h"
#include <iostream>
#include <strstream>

NoteString::NoteString() {
    Date date;
    date.day = 1;
    date.month = 1;
    date.year = 2021;
    setBeginning(date);
    setEnd(date);
    setFlag(false);
}
NoteString::NoteString(const char* msg, Date beg, Date end) {
    setStr(msg);
    setBeginning(beg);
    setEnd(end);
    setFlag(false);
}
NoteString::NoteString(const char* msg, Date beg, Date end, bool flag) {
    setStr(msg);
    setBeginning(beg);
    setEnd(end);
    setFlag(flag);
}
NoteString::NoteString(const NoteString& note) {
    setStr(note.getStr());
    setBeginning(note.getBeginning());
    setEnd(note.getEnd());
    setFlag(note.getFlag());
}
void NoteString::setBeginning(const Date beg) {
    try {
        beg_ = checkDate(beg);
    } catch (std::exception& ex) {
        throw;    //  throwing exception further
    }
}
void NoteString::setEnd(const Date end) {
    try {
        end_ = checkDate(end);
    } catch (std::exception& ex) {
        throw;
    }
}
void NoteString::setFlag(const bool flag) {
    flag_ = flag;
}
char* NoteString::toStr() {
    strstream ss;
    ss << getStr() << ": " << beg_.day << "." << beg_.month << "." << beg_.year << " - "
                    << end_.day << "." << end_.month << "." << end_.year << " Completion - " << flag_ << '\0';
    return ss.str();
}

Date NoteString::toDate(unsigned int day, unsigned int month, unsigned int year) {
    Date date;
    date.day = day;
    date.month = month;
    date.year = year;
    return date;
}

Date NoteString::checkDate(Date date) {
    if ((date.day > 31) || (date.day == 0))
        throw std::invalid_argument("Days number must be less than or equal to 31 and non-zero");
    if ((date.month > 12) || (date.month == 0))
        throw std::invalid_argument("Months number must be less than or equal to 12 and non-zero");
    return date;
}
