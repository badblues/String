#pragma once
#include "String.h"

struct Date {
    unsigned int day;
    unsigned int month;
    unsigned int year;
};

class NoteString : public String {
    public:
        NoteString();
        NoteString(const char* msg, Date beg, Date end);
        NoteString(const char* msg, Date beg, Date end, bool flag);
        NoteString(const NoteString& note);
        void setBeginning(const Date beg);
        void setEnd(const Date end);
        void setFlag(const bool flag);
        char* toStr();
        Date getBeginning() const { return beg_; }
        Date getEnd() const {return end_; }
        bool getFlag() const { return flag_; }
        static Date toDate(unsigned int day, unsigned int month, unsigned int year);
    private:
        Date checkDate(Date date);
        Date beg_;
        Date end_;
        bool flag_;
};
