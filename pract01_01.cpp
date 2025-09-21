

#include <iostream>

using namespace std;


int main()
{
    setlocale(0, "");

    cout << "Для работника с почасовой оплатой труда известны:" << endl;
    double hour, rubH, prem, resl;
    int res;
    cout << "Количество отработанных им часов = ";
    cin >> hour;
    cout << "Ставка почасовой оплаты(руб.в час) = ";
    cin >> rubH;
    cout << "% премии = ";
    cin >> prem;

    resl = rubH * hour * (1 + prem / 100);
    res = resl;

    cout << "Заработано всего: " << res;

    if (res / 10 % 10 == 1)
        cout << " рублей";
    else if (res % 10 == 2 || res % 10 == 3 || res % 10 == 4)
        cout << " рубля";
    else if (res % 10 == 1)
        cout << " рубль";
    else
        cout << " рублей";
}

