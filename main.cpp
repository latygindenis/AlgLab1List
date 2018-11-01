#include <iostream>
#include "List.h"
#include <string>
#include <ctime>

using namespace std;

void testList() {

    List<int> testList;
    int num;
    int min, max;

    long long ins = 0, del = 0, fnd = 0;
    cout << "Введите количество элементов:" << endl;
    cin >> num;
    cout << "Введите нижнюю границу значений:" << endl;
    cin >> min;
    cout << "Введите верхнюю границу значений:" << endl;
    cin >> max;
    for (int i = 0; i < num; i++) {
        testList.addToEnd(min + rand() % (max - min));
    }
    for (int i = 0; i < num; i++) {
//Вставка
        int val = min + rand() % (max - min);
        testList.addNodeByNumber(rand() % num, val);
        ins += testList.operationCount;
//Удаление
        testList.deleteNodeByNumber(rand() % num);
        del += testList.operationCount;
//Поиск
        testList.getPosByValue(min + rand() % (max - min));
        fnd += testList.operationCount;
    }
    ins = ins / num;
    del = del / num;
    fnd = fnd / num;
    cout << "Среднее сложность вставки: " << ins << endl;
    cout << "Среднее сложность удаления: " << del << endl;
    cout << "Среднее сложность поиска: " << fnd << endl;
    testList.cleanList();
}


void menu() {

    cout << "1	опрос размера списка" << endl;
    cout << "2	очистка списка" << endl;
    cout << "3	проверка списка на пустоту" << endl;
    cout << "4	опрос наличия заданного значения" << endl;
    cout << "5	чтение значения с заданным номером в списке" << endl;
    cout << "6	изменение значения с заданным номером в списке" << endl;
    cout << "7	получение позиции в списке с заданным значением" << endl;
    cout << "8	включение нового значения в конец" << endl;
    cout << "9	включение нового значения в начало" << endl;
    cout << "10	включение нового значения в позицию с заданным номером" << endl;
    cout << "11	удаление заданного значения из списка" << endl;
    cout << "12	удаление значения из позиции с заданным номером" << endl;
    cout << "-----------Действия с итератором-------------------" << endl;
    cout << "13   установка на первое значение в списке" << endl;
    cout << "14   переход к следующему значению в списке" << endl;
    cout << "15   переход к предыдущему значению" << endl;
    cout << "16   проверка состояния итератора" << endl;
    cout << "17   прочитать текущее значение" << endl;
    cout << "18   изменить текщее значение" << endl;
    cout << "19   протестировать операции удаления, вставки, поиска" << endl;
    cout << "99   выход" << endl;

}

int main() {
    srand(time(0));
    List<string> myList;
    List<string>::Iterator i(&myList);
    string data;
    int pos;

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
                    cout << "Введите значение: " << endl;
                    cin >> data;
                    cout << myList.contain(data) << endl;
                    break;
                case 5:
                    cout << "Введите номер в списке: " << endl;
                    cin >> data;
                    cout << myList.getValueByNumber(pos) << endl;
                    break;
                case 6:
                    cout << "Введите номер в списке: " << endl;
                    cin >> pos;
                    cout << "Введите новое значение: " << endl;
                    cin >> data;
                    myList.updateValueByNumber(pos, data);
                    break;
                case 7:
                    cout << "Введите значение: " << endl;
                    cin >> data;
                    cout << myList.getPosByValue(data);
                    break;
                case 8:
                    cout << "Введите значение: " << endl;
                    cin >> data;
                    myList.addToEnd(data);
                    break;
                case 9:
                    cout << "Введите значение: " << endl;
                    cin >> data;
                    myList.addToStart(data);
                    break;
                case 10:
                    cout << "Введите номер в списке: " << endl;
                    cin >> pos;
                    cout << "Введите новое значение: " << endl;
                    cin >> data;
                    myList.addNodeByNumber(pos, data);
                    break;
                case 11:
                    cout << "Введите значение: " << endl;
                    cin >> data;
                    myList.deleteNodeByValue(data);
                    break;
                case 12:
                    cout << "Введите номер в списке: " << endl;
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
                    cout << "Введите значение: " << endl;
                    cin >> data;
                    i.write(data);
                    break;
                case 19:
                    testList();
                    break;
                case 99:
                    return 0;//Выход
                default:
                    break;
            }
            if (myList.size > 0) {
                myList.show();
            } else {
                cout << "Пустой список" << endl;
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