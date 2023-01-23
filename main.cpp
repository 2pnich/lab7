#include <iostream>
#include "shaurma.h"
#include "pizza.h"
#include "Drink/drink.h"
#include "soup.h"
#include "fries.h"
#include "basket.h"
#include <windows.h>
#include <vector>
#include <algorithm>
using namespace std;

bool cond(basket k) {
    float border;
    puts("Введите число > сумма");
    cin >> border;
    return (k.sum() >= border);            // предикат - условие поиска
}



bool cmd(basket i1, basket i2) {
//    if (i1.sum() > 0 && i1.sum())  // слева +, справа -   ->  нужно поменять местами
//        return false;
//    else if (i1.sum() < 0 && i2.sum() > 0) // слева - справа + --  не нужно поменять местами
//        return true;
//    else
    return i2.sum() > i1.sum(); // оставшийся случай слева меньше чем справа - false менять местами
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    float summ1;
    string optionInput;
    int option, i = 0, counter_one = 0;
    auto *bas = new basket[20];
    vector <basket> basketVector;
    shaurma _shaurma = shaurma();
    pizza _pizza = pizza();
    drink _drink = drink();
    soup _soup = soup();
    fries _fries = fries();
    bas[i] = basket(_shaurma, _pizza, _drink, _soup, _fries);

    while (option != 5) {
        puts("\nВвести заказ - 1");
        puts("Вывести все заказы - 2");
        puts("сортировка по сумме заказа - 3");
        puts("Поиск суммы больше числа - 4");
        puts("Выход - 5");
        /////TRY БЛОК/////
        cin >> optionInput;
        try {
            option = stoi(optionInput);
            if (option > 5 || option < 1)
                throw ("invalid range");
        } catch (invalid_argument e) {
            cout << ("Нужно вводить цифру!!!");
        } catch (char const *s) {
            cout << ("Диапазон 1-5!!!\n");
        }
        //////////////////

        switch (option) {
            case 1: {
                // ОДНОМЕРНЫЙ МАССИВ ОБЪЕКТОВ //
                bas[i].input();
                basketVector.emplace_back(bas[i]);
                bas[i].output();
//                summ1 = basket::sum(*bas);
//                basket::payment(summ1);
                i++;
                counter_one++;
                break;
            }
            case 2: {
                for (int j = 0; j < counter_one; j++) {
                    bas[j].output();
                    bas[j].sum();
                    puts("");
                }
                break;
            }
            case (3):
                sort(basketVector.begin(), basketVector.end(), cmd);
                for (int j = 0; j < counter_one; j++) {
                    basketVector.at(j).output();
                    basketVector.at(j).sum();
                    puts("");
                }
                break;
            case (4):
                basket ans;
                vector<basket>::iterator da;
                da = find_if(basketVector.begin(),basketVector.end(),cond);
                if(da != basketVector.end()) {
                    da->output();
                    cout << da->sum();
                }
        }
    }
}
