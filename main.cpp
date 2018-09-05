#include <iostream>
#include "List.h"

using namespace std;

int main() {
    List<int> myList;
    List<int>::Iterator i(&myList);

    myList.addToEnd(10);
    myList.addToEnd(2);
    myList.addToEnd(3);
    myList.show();
    try {
        i.first();
        myList.cleanList();
        myList.show();

    }
    catch (int code) {
        switch (code) {
            case EMPTY_LIST_ERR:
                cout << "EMPTY_LIST_ERROR" << endl;
                break;

            case ITERATOR_END_ERR:
                cout<< "ITERATOR_END_ERR" << endl;
                break;
            case ITERATOR_BEGIN_ERR:
                cout<< "ITERATOR_BEGIN_ERR" << endl;
                break;
            case INVALID_INDEX_ERR:
                cout<< "INVALID_INDEX_ERR" <<endl;
                break;
        }

    }

    return 0;
}