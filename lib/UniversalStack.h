#pragma once

template <class T>
    class UniversalStack {
    public:
        UniversalStack();
        UniversalStack(T* obj);
        ~UniversalStack();
        void push(T* obj);
        T pop();
        void addByPosition(unsigned int pos, T* obj);
        void deleteByPosition(unsigned int pos);
        bool isEmpty() { return head == nullptr; };
        T* top() { return current->obj; };
        T* begin();
        T* next();
        T* operator++();
    private:
        struct Node {
            T* obj;
            struct Node* next;
            Node(T* ob) { obj = ob; next = nullptr; };
            ~Node() { delete obj; }
        };
        Node* current;
        Node* head;
};


template <typename T>
UniversalStack<T>::UniversalStack() {
    head = nullptr;
    current = nullptr;
}

template <typename T>
UniversalStack<T>::UniversalStack(T* obj) {
    Node* node = new Node(obj);
    node->next = nullptr;
    head = current = node;
}

template <typename T>
UniversalStack<T>::~UniversalStack() {
    while(head)
        pop();
}

template <typename T>
void UniversalStack<T>::push(T* obj) {
    Node* node = new Node(obj);
    node->next = head;
    head = node;
}

template <typename T>
T UniversalStack<T>::pop() {
    if (head) {
        T tmp = *(head->obj);
        Node* newHead = head->next;
        delete head;
        head = newHead;
        return tmp;
    }
        return {};
}

template <typename T>
void UniversalStack<T>::addByPosition(unsigned int pos, T *obj) {
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

template <typename T>
void UniversalStack<T>::deleteByPosition(unsigned int pos) {
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

template <typename T>
T* UniversalStack<T>::begin() {
    current = head;
    return current->obj;
}

template <typename T>
T* UniversalStack<T>::next() {
    current = current->next;
    return current->obj;
}

template <typename T>
T* UniversalStack<T>::operator++() {
    current = current->next;
    return current->obj;
}

template <>
class UniversalStack<String>{
    public:
        UniversalStack();
        UniversalStack(String* obj);
        ~UniversalStack();
        void push(String* obj);
        String pop();
        bool isEmpty() { return head == nullptr; };
        String* top() { return current->obj; };
        String* begin();
        String* next();
        String* operator++();
        char* getStr();
    private:
        struct Node {
            String* obj;
            struct Node* next;
            Node(String* ob) { obj = ob; next = nullptr; };
            ~Node() { delete obj; }
        };
        Node* current;
        Node* head;
};

UniversalStack<String>::UniversalStack() {
    head = nullptr;
    current = nullptr;
};

UniversalStack<String>::UniversalStack(String *obj) {
    Node* node = new Node(obj);
    node->next = nullptr;
    head = current = node;
}

UniversalStack<String>::~UniversalStack() {
    while(head)
        pop();
}

void UniversalStack<String>::push(String *obj) {
    Node* node = new Node(obj);
    node->next = head;
    head = node;
}

String UniversalStack<String>::pop() {
    if (head) {
        String tmp = *(head->obj);
        Node* newHead = head->next;
        delete head;
        head = newHead;
        return tmp;
    }
    return {};
}

String* UniversalStack<String>::begin() {
    current = head;
    return current->obj;
}

String* UniversalStack<String>::next() {
    current = current->next;
    return current->obj;
}
String* UniversalStack<String>::operator++() {
    current = current->next;
    return current->obj;
}

char* UniversalStack<String>::getStr() {
    return current->obj->getStr();
}
