//
// Created by Latygin on 03.09.2018.
//

#ifndef ALGLAB1LIST_LIST_H
#define ALGLAB1LIST_LIST_H

#include <iostream>
using namespace std;




template <class T>
class List{
public:
    List() {
        head = new Node();
    };
    int size = 0;

    class Node{
    public:
        Node *next;
        Node *prev;
        T data;
    };

    Node *head; //Указатли на начало и конец



    class Iterator{
    public:
        Node *node;
        List *list;
        Iterator (List *l):list(l){

        }

        Iterator* first(){
            node=list->head->next;
            return this;
        };


        Iterator* last(){
            node=list->head->prev;
            return this;
        };

        Iterator& operator--(int){
            node=node->prev;
            return *this;
        };
        Iterator& operator++(int){
            node=node->next;
            return *this;
        };
      //  bool getState();
        T& operator*() { return node->data; }
        friend class List<T>;

    };

    int getListSize(){
        return 0;
    }

    void cleanList(){

    }

    bool isEmpty(){
        return false;
    }

    bool contain(T t){
        return false;
    }
    void append(T data){ //Добавить в конец
        Node *node = new Node();
        node->data = data;

        if (head->prev == NULL) {
            head->prev= node;
            head->next= node;
        } else{
            head->prev->next = node;
            head->prev = node;
        }
        size++;
    }

    void show(){
        Node *node = head->next;
        while (node){
            cout<<node->data<<" ";
            node = node->next;
        }
    }



    virtual ~List() {

    }
};

#endif //ALGLAB1LIST_LIST_H
