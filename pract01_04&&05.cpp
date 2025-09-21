

#include <iostream>

using namespace std;

void result(double hour, double rubH, double prem, double &res, double &pNa, double &pSu)
{
    res = hour * rubH * (1 + prem / 100);
    pNa = res * 0.13;
    pSu = res - pNa;
}

void Worker(double &hour, double &rubH, double &prem)
{
    cout << "Для работника с почасовой оплатой труда известны:" << endl;

    cout << "Количество отработанных им часов = ";
    cin >> hour;
    cout << "Ставка почасовой оплаты(руб.в час) = ";
    cin >> rubH;
    cout << "% премии = ";
    cin >> prem;
}

int main()
{
    setlocale(0, "");
    int k = 1, mk;
    double mSu = 0; // Для макс
    double sSu = 0;

    while (k < 3)
    {
        double hour, rubH, prem, res, pNa, pSu;

        cout << "Работник #" << k << endl;
        Worker(hour, rubH, prem);

        result(hour, rubH, prem, res, pNa, pSu);

        cout << "Заработано всего: " << res << endl;

        cout << "Вычтено подоходным налогом: " << pNa << endl;

        cout << "Сумма с учётом вычета подоходного налога: " << pSu << endl;

        sSu += pSu;

        if (pSu > mSu)
        {
            mSu = pSu;
            mk = k;
        }
           

        k++;
    }
    
    cout << "Больше заработал работник под номером" << mk << endl;
    cout << "Вместе работники заработали (с вычетом налога): " << sSu << endl;

    return 0;
}

