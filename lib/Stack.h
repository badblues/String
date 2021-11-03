#pragma once
#include "String.h"

class Stack {
    public:
        Stack();
        Stack(String* obj);
        ~Stack();
        void push(String* obj);
        void pop();
        void addByPosition(unsigned int pos, String* obj);
        void deleteByPosition(unsigned int pos);
        bool isEmpty() { return head == nullptr; }
        String& top() { return *(current->obj); }
        String& begin();
        String& next();
        String& operator ++();
    private:
        // 0_0 ?????
        struct Node {
            String* obj;
            struct Node* next;
            // 0_0 ?????
            Node(String *ob) {obj = ob; next = nullptr; }
        };
        Node* current;
        Node* head;
};


