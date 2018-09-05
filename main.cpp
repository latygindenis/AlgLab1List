#include <iostream>
#include "List.h"

using namespace std;

void menu() {

    cout << "1	����� ������� ������" << endl;
    cout << "2	������� ������" << endl;
    cout << "3	�������� ������ �� �������" << endl;
    cout << "4	����� ������� ��������� ��������" << endl;
    cout << "5	������ �������� � �������� ������� � ������" << endl;
    cout << "6	��������� �������� � �������� ������� � ������" << endl;
    cout << "7	��������� ������� � ������ � �������� ���������" << endl;
    cout << "8	��������� ������ �������� � �����" << endl;
    cout << "9	��������� ������ �������� � ������" << endl;
    cout << "10	��������� ������ �������� � ������� � �������� �������" << endl;
    cout << "11	�������� ��������� �������� �� ������" << endl;
    cout << "12	�������� �������� �� ������� � �������� �������" << endl;
    cout << "-----------�������� � ����������-------------------" << endl;
    cout << "13   ��������� �� ������ �������� � ������" << endl;
    cout << "14   ������� � ���������� �������� � ������" << endl;
    cout << "15   ������� � ����������� ��������" << endl;
    cout << "16   �������� ��������� ���������" << endl;
    cout << "17   ��������� ������� ��������" << endl;
    cout << "18   �������� ������ ��������" << endl;
    cout << "99   �����" << endl;

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
                    cout << "������� ��������: " << endl;
                    cin >> data;
                    cout << myList.contain(answer) << endl;
                    break;
                case 5:
                    cout << "������� ����� � ������: " << endl;
                    cin >> data;
                    cout << myList.getValueByNumber(data);
                    break;
                case 6:
                    cout << "������� ����� � ������: " << endl;
                    cin >> pos;
                    cout << "������� ����� ��������: " << endl;
                    cin >> data;
                    myList.updateValueByNumber(pos, data);
                    break;
                case 7:
                    cout << "������� ��������: " << endl;
                    cin >> data;
                    cout << myList.getPosByValue(data);
                    break;
                case 8:
                    cout << "������� ��������: " << endl;
                    cin >> data;
                    myList.addToEnd(data);
                    break;
                case 9:
                    cout << "������� ��������: " << endl;
                    cin >> data;
                    myList.addToStart(data);
                    break;
                case 10:
                    cout << "������� ����� � ������: " << endl;
                    cin >> pos;
                    cout << "������� ����� ��������: " << endl;
                    cin >> data;
                    myList.addNodeByNumber(pos, data);
                    break;
                case 11:
                    cout << "������� ��������: " << endl;
                    cin >> data;
                    myList.deleteNodeByValue(data);
                    break;
                case 12:
                    cout << "������� ����� � ������: " << endl;
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
                    cout << "������� ��������: " << endl;
                    cin >> data;
                    i.write(data);
                    break;
                case 99:
                    return 0;//�����
                    break;
                default:
                    break;
            }
            if (myList.size > 0){
                myList.show();
            } else{
                cout<<"������ ������"<<endl;
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