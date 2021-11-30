#include "Stack.h"
#include <exception>

Stack::Stack() {
    head = nullptr;
    current = nullptr;
}

Stack::Stack(String* obj) {
    Node* node = new Node(obj);
    node->next = nullptr;
    head = current = node;
}

Stack::~Stack() {
    while(head)
        pop();
}

void Stack::push(String* obj) {
    Node* node = new Node(obj);
    node->next = head;
    head = node;
}

String Stack::pop() {
    if (head) {
        String tmp(*(head->obj));
        Node* newHead = head->next;
        delete head;
        head = newHead;
        return tmp;
    }
        return {};
}

void Stack::addByPosition(unsigned int pos, String *obj) {
    if (pos == 0)
        push(obj);
    else {
        Node* tmp = head;
        for (int i = 1; i < pos; i++) {
            if (head->next == nullptr)
                throw out_of_range("There is no such member");
            head = head->next;
        }
        Node* node = new Node(obj);
        node->next = head->next;
        head->next = node;
        head = tmp;
    }
}

void Stack::deleteByPosition(unsigned int pos) {
    if (pos == 0)
        pop();
    else {
        for (int i = 1; i < pos; i++) {
            if (head->next == nullptr)
                throw out_of_range("There is no such member");
            head = head->next;
        }
        Node* tmp = head->next;
        head->next = head->next->next;
        delete tmp;
    }
}

String* Stack::begin() {
    current = head;
    return current->obj;
}

String* Stack::next() {
    current = current->next;
    return current->obj;
}

String* Stack::operator++() {
    current = current->next;
    return current->obj;
}
