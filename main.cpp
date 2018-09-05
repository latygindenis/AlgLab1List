#include <iostream>
#include "List.h"

using namespace std;

void menu() {

    cout << "1	опрос размера списка" << endl;
    cout << "2	очистка списка" << endl;
    cout << "3	проверка списка на пустоту" << endl;
    cout << "4	опрос наличи€ заданного значени€" << endl;
    cout << "5	чтение значени€ с заданным номером в списке" << endl;
    cout << "6	изменение значени€ с заданным номером в списке" << endl;
    cout << "7	получение позиции в списке с заданным значением" << endl;
    cout << "8	включение нового значени€ в конец" << endl;
    cout << "9	включение нового значени€ в начало" << endl;
    cout << "10	включение нового значени€ в позицию с заданным номером" << endl;
    cout << "11	удаление заданного значени€ из списка" << endl;
    cout << "12	удаление значени€ из позиции с заданным номером" << endl;
    cout << "-----------ƒействи€ с итератором-------------------" << endl;
    cout << "13   установка на первое значение в списке" << endl;
    cout << "14   переход к следующему значению в списке" << endl;
    cout << "15   переход к предыдущему значению" << endl;
    cout << "16   проверка состо€ни€ итератора" << endl;
    cout << "17   прочитать текущее значение" << endl;
    cout << "18   изменить текщее значение" << endl;
    cout << "99   выход" << endl;

}

int main() {
    List<int> myList;
    List<int>::Iterator i(&myList);
    int data, pos;

    setlocale(LC_ALL, "Russian");
    menu();

    while (true) {

        try {
            int answer;
            cout << ">>  ";
            cin >> answer;
            switch (answer) {
                case 1:
                    cout << myList.getSize() << endl;
                    break;
                case 2:
                    myList.cleanList();
                    break;
                case 3:
                    cout << myList.isEmpty() << endl;
                    break;
                case 4:
                    cout << "¬ведите значение: " << endl;
                    cin >> data;
                    cout << myList.contain(answer) << endl;
                    break;
                case 5:
                    cout << "¬ведите номер в списке: " << endl;
                    cin >> data;
                    cout << myList.getValueByNumber(data);
                    break;
                case 6:
                    cout << "¬ведите номер в списке: " << endl;
                    cin >> pos;
                    cout << "¬ведите новое значение: " << endl;
                    cin >> data;
                    myList.updateValueByNumber(pos, data);
                    break;
                case 7:
                    cout << "¬ведите значение: " << endl;
                    cin >> data;
                    cout << myList.getPosByValue(data);
                    break;
                case 8:
                    cout << "¬ведите значение: " << endl;
                    cin >> data;
                    myList.addToEnd(data);
                    break;
                case 9:
                    cout << "¬ведите значение: " << endl;
                    cin >> data;
                    myList.addToStart(data);
                    break;
                case 10:
                    cout << "¬ведите номер в списке: " << endl;
                    cin >> pos;
                    cout << "¬ведите новое значение: " << endl;
                    cin >> data;
                    myList.addNodeByNumber(pos, data);
                    break;
                case 11:
                    cout << "¬ведите значение: " << endl;
                    cin >> data;
                    myList.deleteNodeByValue(data);
                    break;
                case 12:
                    cout << "¬ведите номер в списке: " << endl;
                    cin >> pos;
                    myList.deleteNodeByNumber(pos);
                    break;
                case 13:
                    i.first();
                    break;
                case 14:
                    i++;
                    break;
                case 15:
                    i--;
                    break;
                case 16:
                    cout << i.getState() << endl;
                    break;
                case 17:
                    cout << i.read() << endl;
                    break;
                case 18:
                    cout << "¬ведите значение: " << endl;
                    cin >> data;
                    i.write(data);
                    break;
                case 99:
                    return 0;//¬ыход
                    break;
                default:
                    break;
            }
            if (myList.size > 0){
                myList.show();
            } else{
                cout<<"ѕустой список"<<endl;
            }
        }
        catch (int code) {
            switch (code) {
                case EMPTY_LIST_ERR:
                    cout << "EMPTY_LIST_ERROR" << endl;
                    break;

                case ITERATOR_END_ERR:
                    cout << "ITERATOR_END_ERR" << endl;
                    break;

                case ITERATOR_BEGIN_ERR:
                    cout << "ITERATOR_BEGIN_ERR" << endl;
                    break;

                case INVALID_INDEX_ERR:
                    cout << "INVALID_INDEX_ERR" << endl;
                    break;
                default:
                    break;
            }

        }
    }

    return 0;
}