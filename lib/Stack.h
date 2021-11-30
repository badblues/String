#pragma once
#include "String.h"


class Stack {
    public:
        Stack();
        Stack(String* obj);
        ~Stack();
        void push(String* obj);
        String pop();
        void addByPosition(unsigned int pos, String* obj);
        void deleteByPosition(unsigned int pos);
        bool isEmpty() { return head == nullptr; }
        String* top() { return current->obj; }
        String* begin();
        String* next();
        String* operator ++();
    private:
        struct Node {
            String* obj;
            struct Node* next;
            Node(String *ob) {obj = ob; next = nullptr; }
            ~Node() { delete obj; }
        };
        Node* current;
        Node* head;
};


