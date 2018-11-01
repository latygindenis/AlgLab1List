//
// Created by Latygin on 03.09.2018.
//

#ifndef ALGLAB1LIST_LIST_H
#define ALGLAB1LIST_LIST_H


#define EMPTY_LIST_ERR 1
#define INVALID_INDEX_ERR 2
#define ITERATOR_END_ERR 3
#define ITERATOR_BEGIN_ERR 4


#include <iostream>

using namespace std;


template<class T>
class List {
public:

    // Конструктор по умолчанию
    List() {
        begin = end = nullptr;
    };


    // Конструктор копирования
    List(List &list) {
        begin = new Node();

        Node *n = list.begin;
        begin->next = n->next;
        n = n->next;
        while (n) {
            addToEnd(n->data);
            n = n->next;
        }
    }


    int size = 0;
    long long operationCount = 0;

    class Node {
    public:
        Node *next;
        Node *prev;
        T data;

        Node(T data) {
            this->data = data;
        }

        Node() {
            next = prev = nullptr;
        }
    };


    Node *begin;
    Node *end;


    class Iterator {
    public:
        Node *node;
        List *list;

        Iterator(List *l) : list(l) {

        }

        Iterator *first() {
            if (list->isEmpty()) throw EMPTY_LIST_ERR;
            node = list->begin;
            return this;
        };


        Iterator *last() {
            if (list->isEmpty()) throw EMPTY_LIST_ERR;
            node = list->end;
            return this;
        };

        Iterator &operator--(int) {
            if (list->isEmpty()) throw EMPTY_LIST_ERR;
            if (isBegin()) throw ITERATOR_BEGIN_ERR;
            node = node->prev;
            return *this;
        };

        Iterator &operator++(int) {
            if (list->isEmpty()) throw EMPTY_LIST_ERR;
            if (isEnd()) throw ITERATOR_END_ERR;
            node = node->next;
            return *this;
        };

        bool isEnd() {
            return node->next == nullptr;
        };

        bool isBegin() {
            return node->prev == nullptr;
        }

        T read() {
            if (list->isEmpty()) throw EMPTY_LIST_ERR;
            return node->data;
        }

        void write(T data) {
            if (list->isEmpty()) throw EMPTY_LIST_ERR;
            node->data = data;
        }

        T &operator*() { return read(); }

        bool getState() {
            if (this->node == nullptr) {
                return false;
            } else {
                return true;
            }
        }

        friend class List<T>;

    };

    int getSize() {
        return size;
    }

    void cleanList() {
        Node *node = begin;
        while (node) {
            Node *buf = node->next;
            delete node;
            node = buf;
        }
        begin = end = nullptr;
        size = 0;
    }

    bool isEmpty() {
        return size <= 0;
    }

    bool contain(T t) {
        Node *node = begin->next;
        while (node) {
            if (node->data == t) {
                return true;
            }
            node = node->next;
        }
        return false;
    }

    T getValueByNumber(int number) {

        return getNodeByNumber(number)->data;
    }

    void updateValueByNumber(int number, T newData) {
        getNodeByNumber(number)->data = newData;
    }

    Node *getNodeByNumber(float number) {
        operationCount = 0;
        Node *node;

        if (number / size > 0.5) {
            node = end;
            for (int i = 0; i < size - number; i++, operationCount++) {
                if (i == number) { break; }
                node = node->prev;

            }
        } else {
            node = begin;
            for (int i = 0; i < number; i++, operationCount++) {
                if (i == number) { break; }
                node = node->next;
            }
        }
        return node;
    }

    void addToEnd(T data) { //Добавить в конец

        if (end == nullptr) {
            begin = end = new Node(data);
            begin->next = end;
            end->prev = begin;
        } else {
            Node *node = new Node();
            node->data = data;

            end->next = node;
            node->prev = end;
            end = node;
        }

        size++;
    }

    void addToStart(T data) { //Добавить в начало

        if (begin == nullptr) {
            begin = end = new Node(data);
        } else {
            Node *node = new Node();
            node->data = data;

            begin->prev = node;
            node->next = begin;
            begin = node;
        }
        size++;

    }

    void addNodeByNumber(int number, T data) {
        operationCount = 0;

        if (number == size) {
            addToEnd(data);
            operationCount++;
        } else if (number == 0) {
            addToStart(data);
            operationCount++;
        } else {


            Node *node = new Node;
            node->data = data;
            Node *buf = getNodeByNumber(number);

            node->next = buf;
            buf->prev->next = node;
            node->prev = buf->prev;
            buf->prev = node;
        }
    }

    void deleteNodeByValue(T data) {
        Node *node = begin;
        while (node) {
            if (node->data == data) {
                deleteNode(node);
                break;
            }
            node = node->next;
            operationCount++;
        }
    }

    void deleteNode(Node *node) {
        if (node->prev == nullptr) {
            begin = node->next;
            node->next->prev = nullptr;
            delete node;
        } else if (node->next == nullptr) {
            end = node->prev;
            node->prev->next = nullptr;
            delete node;
        } else {
            node->next->prev = node->prev;
            node->prev->next = node->next;
            delete node;
        }
    }

    void deleteNodeByNumber(int number) {
        operationCount = 0;
        deleteNode(getNodeByNumber(number));
    }

    void show() {
        Node *node = begin;
        while (node) {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }

    int getPosByValue(T value) {
        operationCount = 0;
        Node *node = begin;
        int position = 0;
        while (node) {
            if (node->data == value) {
                return position;
            }
            node = node->next;
            position++;
            operationCount++;
        }
        return -1;
    }

    virtual ~List() {
        cleanList();
    }
};

#endif //ALGLAB1LIST_LIST_H
