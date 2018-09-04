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
    myList.cleanList();
    try {
        i.first();
    }
    catch (int code) {
        switch (code) {
            case EMPTY_LIST_ERR:
                cout << "EMPTY_LIST_ERROR" << endl;
                break;
        }

    }

    return 0;
}