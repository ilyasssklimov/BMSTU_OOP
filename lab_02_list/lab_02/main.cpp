#include <iostream>

using namespace std;
#include "list.hpp"


void print_int_list(List<int> &list)
{
    if (list.get_size())
        for (auto node: list)
            cout << node.get_data() << " ";
    else
        cout << "Empty list";
}


int main()
{
    cout << "TESTING OF CLASS 'LIST'\n" << endl;

    cout << "CONSTRUCTORS\n";

    cout << "EMPTY: ";
    List<int> list1;
    print_int_list(list1);

    cout << "\nFROM ARRAY: ";
    int array[] = { 1, 2, 3, 4, 5 };
    List<int> list2(array, 5);
    print_int_list(list2);

    cout << "\nFROM LIST: ";
    List<int> list3(list2);
    print_int_list(list3);

    cout << "\nINITIALAZER: ";
    List<int> list4({ 1, 2, 3, 4, 5, 6 });
    print_int_list(list4);


    cout << "\n\nADD\n";
    cout << "FRONT (WITH DATA): ";
    List<int> list5({ 4, 5, 6 });
    list5.add_front(3);
    list5.add_front(2);
    list5.add_front(1);
    print_int_list(list5);

    List<int> tmp = { 3, 2, 1 };
    cout << "\nFRONT (WITH LIST): ";
    List<int> list6 = { 4, 5 };
    list6.add_front(tmp);
    print_int_list(list6);

    cout << "\nBACK (WITH DATA): ";
    List<int> list7 = {1, 2};
    list7.add_back(3);
    list7.add_back(4);
    list7.add_back(5);
    print_int_list(list7);

    cout << "\nBACK (WITH LIST): ";
    List<int> list8 = { 4, 5 };
    list8.add_back(tmp);
    print_int_list(list8);

    cout << "\n\nINSERT:\n";
    cout << "TO 0 POSTION: ";
    List<int> list9 = { 1, 2, 3 };
    list9.insert(list9.begin(), 0);
    print_int_list(list9);

    cout << "\nTO 1 POSTION: ";
    List<int> list10 = { 1, 2, 3 };
    list10.insert(list10.begin() + 1, 0);
    print_int_list(list10);


    cout << "\n\nEQUAL:\n";
    List<int> list11 = { 1, 2, 3 };
    List<int> list12 = { 1, 2, 3 };
    List<int> list13 = { 1, 2, 5 };
    List<int> list14 = { 1, 2 };
    cout << "YES: " << (list11 == list12);
    cout << "\nYES: " << (list11 == list13);
    cout << "\nYES: " << (list11 == list14);
    cout << "\nNO: " << (list11 != list12);
    cout << "\nNO: " << (list11 != list13);
    cout << "\nNO: " << (list11 != list14);

    cout <<"\n\n'+': ";
    List<int> list15 = {1, 2};
    List<int> list16 = {3, 4, 5};
    print_int_list(list15);
    cout << "+ ";
    print_int_list(list16);
    cout << "= ";
    print_int_list(list15 + list16);

    List<int> list18 = {1, 2};
    List<int> list19 = {3, 4, 5};
    list18 += list19;
    cout << "\n'+=': ";
    print_int_list(list18);

    list18 = list19;
    cout << "\n'=': ";
    print_int_list(list18);

    cout << "\n\nREVERSE:\n";
    List<int> list20 = { 1, 2, 3, 4, 5, 6 };
    list20.reverse();
    print_int_list(list20);

    List<int> list21 = { 1, 2, 3 };
    cout << "\n\nSize of ";
    print_int_list(list21);
    cout << "is " << list21.get_size();

    cout << "\nCLEAR: ";
    list21.clear();
    print_int_list(list21);

    cout << "\n";
    List<int> list31 = { 1, 2, 3 };
    list31.merge({ 4, 5, 6, 7 });
    print_int_list(list31);

    cout << "\n";
    List<int> list34 = { 1, 2, 3, 4 };
    list34.remove(list34.begin() + 2);
    print_int_list(list34);

    cout << "\n";
    List<int> list36 = { 1, 2, 3, 4 };
    list36.insert(list36.begin() + 2, { 0, 0, 0 });
    print_int_list(list36);

    cout << "\n";
    List<int> list42 = { 1 };
    list42.insert(list42.begin(), list36.begin(), 2);
    print_int_list(list42);

    cout << "\n";
    List<int> list43 = { 4, 5 };
    List<int> list44 = { 1, 2};
    list43.add_back(list44.begin(), list44.begin() + 1);
    print_int_list(list43);

    cout << "\n";
    List<int> list45 = { 4, 5 };
    List<int> list46 = { 1, 2};
    list46.add_back(list45.begin(), 2);
    print_int_list(list46);

    cout << "\n";
    List<int> list47 = { 4, 5 };
    List<int> list48 = { 1, 2 };
    list47.add_front(list48.begin(), list48.begin() + 1);
    print_int_list(list47);

    cout << "\n";
    List<int> list49 = { 4, 5 };
    List<int> list50 = { 1, 2 };
    list49.add_front(list50.begin(), 2);
    print_int_list(list49);

    cout << "\n";
    List<int> list51 = { 1, 2, 3, 4 };
    list51.remove(list51.begin() + 1, list51.begin() + 2);
    print_int_list(list51);
    return 0;
}
