#pragma once
#include <ctime>
#include "String.h"


class NoteString : public String {
    public:
        NoteString();
        NoteString(const char* msg, tm beg, tm end);
        NoteString(const char* msg, tm beg, tm end, bool flag);
        NoteString(const NoteString& note);
        void setBeginning(tm beg);
        void setEnd(tm end);
        void setFlag(bool flag);
        const char* toStr();
        virtual tm getBeginning() const { return beg_; }
        virtual tm getEnd() const {return end_; }
        virtual bool getFlag() const { return flag_; }
    private:
        tm beg_{};
        tm end_{};
        bool flag_;
};
