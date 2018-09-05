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
        head = new Node();
    };


    // Конструктор копирования
    List(List &list) {
        head = new Node();
        Node *n = list.head;

        head->next = n->next;

        n = n->next;
        while (n) {
            addToEnd(n->data);
            n = n->next;
        }
    }


    int size = 0;

    class Node {
    public:
        Node *next;
        Node *prev;
        T data;
    };

    Node *head; //Указатели на начало и конец



    class Iterator {
    public:
        Node *node;
        List *list;

        Iterator(List *l) : list(l) {

        }

        Iterator *first() {
            if (list->isEmpty()) throw EMPTY_LIST_ERR;
            node = list->head->next;
            return this;
        };


        Iterator *last() {
            if (list->isEmpty()) throw EMPTY_LIST_ERR;
            node = list->head->prev;
            return this;
        };

        Iterator &operator--(int) {
            if(list->isEmpty()) throw EMPTY_LIST_ERR;
            if(isBegin()) throw ITERATOR_BEGIN_ERR;
            node = node->prev;
            return *this;
        };

        Iterator &operator++(int) {
            if(list->isEmpty()) throw EMPTY_LIST_ERR;
            if(isEnd()) throw ITERATOR_END_ERR;
            node = node->next;
            return *this;
        };

        bool isEnd() {
            return node->next == NULL;
        };

        bool isBegin() {
            return node->prev == NULL;
        }

        T read(){
            if(list->isEmpty()) throw EMPTY_LIST_ERR;
            return node->data;
        }

        void write(T data){
            if(list->isEmpty()) throw EMPTY_LIST_ERR;
            node->data = data;
        }

        T &operator*() { return read(); }

        bool getState(){
            if (this->node == NULL){
                return false;
            } else{
                return true;
            }
        }

        friend class List<T>;

    };

    int getSize() {
        return size;
    }

    void cleanList() {
        Node *node = head->next;
        while (node) {
            Node *buf = node;
            buf = buf->next;
            delete node;
            node = buf;
        }
        head->next = NULL;
        head->prev = NULL;
        size = 0;
    }

    bool isEmpty() {
        return size <= 0;
    }

    bool contain(T t) {
        Node *node = head->next;
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

    Node *getNodeByNumber(int number) {
        Node *node;
        if (number / size > 0.5) {
            node = head->prev;
            for (int i = 0; i < size - number; i++) {
                if (i == number) { break; }
                node = node->prev;
            }
        } else {
            node = head->next;
            for (int i = 0; i < number; i++) {
                if (i == number) { break; }
                node = node->next;
            }
        }
        return node;
    }

    void addToEnd(T data) { //Добавить в конец
        Node *node = new Node();
        node->data = data;

        if (head->prev == NULL) {
            head->prev = node;
            head->next = node;
        } else {
            head->prev->next = node;
            node->prev = head->prev;
            head->prev = node;
        }
        size++;
    }

    void addToStart(T data) { //Добавить в начало
        Node *node = new Node();
        node->data = data;

        if (head->prev == NULL) {
            head->prev = node;
            head->next = node;
        } else {
            head->next->prev = node;
            node->next = head->next;
            head->next = node;
        }
        size++;
    }

    void addNodeByNumber(int number, T data) {
        if (number == size) {
            addToEnd(data);
        } else if (number == 0) {
            addToStart(data);
        } else {
            Node *node = new Node;
            node->data = data;
            Node *buf = head->next;
            for (int i = 0; i < number; i++) {
                buf = buf->next;
                cout << buf->data << endl;
            }

            node->next = buf;
            buf->prev->next = node;
            node->prev = buf->prev;
            buf->prev = node;
        }
    }

    void deleteNodeByValue(T data) {
        Node *node = head->next;
        while (node) {
            if (node->data == data) {
                deleteNode(node);
                break;
            }
            node = node->next;
        }
    }

    void deleteNode(Node *node) {
        if (node->prev == NULL) {
            head->next = node->next;
            node->next->prev = NULL;
            delete node;
        } else if (node->next == NULL) {
            head->prev = node->prev;
            node->prev->next = NULL;
            delete node;
        } else {
            node->next->prev = node->prev;
            node->prev->next = node->next;
            delete node;
        }
    }

    void deleteNodeByNumber(int number) {
        deleteNode(getNodeByNumber(number));
    }

    void show() {
        Node *node = head->next;
        while (node) {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }

    int getPosByValue(T value) {
        Node *node = head->next;
        int position = 0;
        while (node) {
            if (node->data == value) {
                return position;
            }
            node = node->next;
            position++;
        }
        throw ITERATOR_END_ERR;
    }

    virtual ~List() {
        cleanList();
        delete head;
    }
};

#endif //ALGLAB1LIST_LIST_H
