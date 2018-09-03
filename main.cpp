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
    i.first();
    cout << *i << endl;
    i.last();
    cout << *i << endl;
    *i = 100;
    myList.show();

    if (myList.contain(100)) {
        cout << myList.getValueByNumber(0) << endl;
    }
    myList.show();
    myList.cleanList();
    myList.show();

    myList.addToEnd(1);
    myList.addToEnd(2);
    myList.addToEnd(3);
    myList.show();
    myList.updateValueByNumber(2, 76);
    cout << myList.getValueByNumber(2) << endl;
    myList.show();
    cout << myList.getPosByValue(78) << endl;
    myList.addToStart(677);
    myList.show();
    myList.addNodeByNumber(4, 100);
    myList.show();
    myList.deleteNodeByValue(2);
    myList.show();
    myList.deleteNodeByValue(100);
    myList.show();
    myList.deleteNodeByNumber(1);
    myList.show();
    myList.deleteNodeByNumber(0);
    myList.show();
    myList.deleteNodeByNumber(0);
    myList.show();

    return 0;
}