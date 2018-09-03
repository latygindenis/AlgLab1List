#include <iostream>
#include "List.h"

using namespace std;

int main() {
    List<int> myList;
    List<int>::Iterator i(&myList);
    myList.append(1);
    myList.append(2);
    myList.append(3);
    myList.show();
    i.first();
    cout<<*i<<endl;
    i.last();
    cout<<*i<<endl;
    return 0;
}